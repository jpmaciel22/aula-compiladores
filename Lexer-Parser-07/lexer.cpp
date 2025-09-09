#include "lexer.h"
#include <iostream>
#include <sstream>
using std::stringstream;
using std::cin;

//construtor
Lexer::Lexer(){
    //insere palavras chaves na tabela de ids
    id_table["true"] = Id{Tag::TRUE, "true"};
    id_table["false"] = Id{Tag::FALSE, "false"};

    // inciai leitura da entrada
    peek = cin.get();
}

//retorna numero da linha atual
int Lexer::Lineno(){
    return line;
}

//retorna tokens para o analisador sintatico
Token * Lexer::Scan(){
    //ignora espaco em branco
    while(isspace(peek)){
        if (peek == '\n'){
            line += 1;
        }
        peek = cin.get();
    }

    if(isdigit(peek)){
        int v = 0;
        do{
            int n = peek - '0';
            v = 10*v+n;
            peek = cin.get();
        }while(isdigit(peek));

        token.n = Num{v};
        return &token.n;
    };

    if(isalpha(peek)){
        stringstream ss;
        do{
            ss << peek;
            peek = cin.get();
        }
        while (isalpha(peek));

        string s = ss.str();
        auto pos = id_table.find(s); // procura o alfanumerico na id table

        //se ja esta na tabela
        if(pos != id_table.end()){
            token.i = pos->second; // passa o token que é o valor da chave da tabela
            return &token.i;
        }

        //se o token ainda nao esta na tabela
        Id new_id {Tag::ID, s};
        id_table[s] = new_id;

        token.i = new_id;
        return &token.i;
    }

    // nao entrou em nenhuma condicao ate agora
    Token op {peek};
    peek = ' ';

    //retorna o token do operador/simbolo
    token.t = op;
    return &token.t;
}