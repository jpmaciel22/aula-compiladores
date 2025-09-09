#include "parser.h"
#include "error.h"
#include <iostream>
#include <sstream>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::stringstream;

void Parser::Expr(){
    //expr -> term add
    Term();
    while(true){ //add aqui
            //add -> + term {print(+)} add
            if(lookahead -> tag == '+'){
                Match('+');
                Term();
                cout << '+';
            }
            //add -> - term {print(-)} add
            if(lookahead -> tag == '-'){
                    Match('-');
                    Term();
                    cout << '-';
            }
            // add -> epsilon
            else return;
    }
}

void Parser::Term(){
    //term -> fact mult
    Fact();
    while(true){
        //mult -> * fact {print(*)} mult
        if(lookahead -> tag == '*'){
            Match('*');
            Fact();
            cout << '*';
        }
        // mult -> / fact {print(/)} mult
        if(lookahead -> tag == '/'){
            Match('/');
            Fact();
            cout << '/';
        }
        // mult -> epsilon
        else return;
    }
}

void Parser::Fact(){
    //fact -> (expr)
    if(lookahead -> tag == '('){
        Match('(');
        Expr();
        if(!Match(')')){
            throw SyntaxError{ scanner.Lineno(), "\')\' esperado"};
        }
    }
    //fact -> num {print(num.valor)}
    else if (lookahead -> tag == Tag::NUM){
        cout << '[' << lookahead->toString() << ']';
        Match(Tag::NUM);
    }
    //fact -> id {print(id.nome)}
    else if(lookahead -> tag == Tag::ID){
        cout << '[' << lookahead->toString()<<']';
        Match(Tag::ID); // nao precisaria pois ja sabemos que é verdade e deveria ser antes do print por ser pos fixada mas enfim so por questao didatica
    }
    //erro de sintaxe
    else{
        stringstream ss;
        ss << "simbolo \'" << lookahead -> toString() << "\' invalido";
        throw SyntaxError{scanner.Lineno(), ss.str()};
    }
}

bool Parser::Match(int tag){
    if(tag == lookahead->tag){
        lookahead = scanner.Scan();
        return true;
    }
    return false;
}

Parser::Parser(){
    lookahead = scanner.Scan();
}

void Parser::Start(){
    Expr(); // chama o simbolo inicial da gramatica
    //como o salto de linha nao gera mais um token espera-se EOF(ctrl + d)
    if(lookahead -> tag != EOF){
        stringstream ss;
        ss << "símbolo \'" << lookahead -> toString() << "\' inválido";
        throw SyntaxError{scanner.Lineno(), ss.str()};
    }
}