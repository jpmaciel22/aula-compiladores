#include "parser.h"
#include <iostream>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;

void Parser::Expr(){
    //expr => term oper
    Term();
    // esse while é o oper. deixamos assim por otimizacao
    while(true){
        // oper => + term {print(+)} oper
        if(lookahead == '+')
        {
            Match('+');
            Term();
            cout << '+';
        }
        // oper => - term {print(-)} oper
        else if(lookahead == '-'){
            Match('-');
            Term();
            cout << '-';
        }
        else return; // oper => ε
    }
};

void Parser::Term(){
    if(isdigit(lookahead)){
        char temp = lookahead; cout << temp; Match(lookahead);
    }else{
        throw SyntaxError{};
    };
}

void Parser::Match(char t){
    if(t == lookahead){
        lookahead = cin.get();
    }
    else{
        throw SyntaxError{};
    }
}

Parser::Parser(){
    lookahead = 0; // não é necessário pois ja inicia recebendo um caractere de entrada.
}

void Parser::Start(){
    lookahead = cin.get();
    Expr();
    if(lookahead != '\n'){throw SyntaxError{};}
}