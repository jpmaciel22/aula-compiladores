#include "lexer.h"
#include <iostream>
#include <sstream>
using std::cin;
using std::cout;
using std::stringstream;

Lexer::Lexer(){
    //ao iniciar inserir as palavras-reservadas na tablea de id's
    id_table["true"] = Id{Tag::TRUE, "true"};
    id_table["false"] = Id{Tag::FALSE, "false"};
}

Token Lexer::Scan(){
    
    //salta espacos em branco, tabulacoes e novas linhas
    while(isspace(peek)){
        if(peek == '\n'){
            line += 1;}
        peek = cin.get();
    }

    if(isdigit(peek)){
        int v = 0;

        do{
            // converte caractere 'n' para digito numerico n
            int n = peek - '0';
            v = 10 * v + n; // à la dragon book
            peek = cin.get();
        }
        while(isdigit(peek));

        //DEBUG: exibe o token reconhecido
        cout << "<NUM," << v <<"> ";
        
        // retorna o token NUM
        return Num{v};
    }

    if(isalpha(peek)){
        stringstream ss;

        do{
            ss << peek; // vai passando os caracteres enqaunto for caractere nesse buffer 
            peek = cin.get();
        }while(isalpha(peek));

        string s = ss.str(); // dps transforma o buffer em string
        auto pos = id_table.find(s); // vejo se ja esta identificado na nossa tabela e recebe um ponteiro de volta e guarda em pos
        
        // se o lexema ja esta na tablea
        if(pos != id_table.end()){

            //Debug: exibe o token reconhecido
            switch(pos -> second.tag){
                case TRUE: cout << "<TRUE," << pos->second.name << "> "; break;
                case FALSE: cout << "<FALSE," << pos->second.name << "> "; break;
                default: cout << "<ID," << pos->second.name << "> "; break;
            }
            //retorna o TOKEN ID, o primeiro elemento é a string e o segundo o token.
            return pos-> second;
        }

        //se o lexema ainda não esta na tabela?
        Id new_id {Tag::ID,s}; // inserimos.
        id_table[s] = new_id;

        //DEBUG: exibe o token reconhecido:
        cout << "<ID," << new_id.name << ">";

        // retorna o token ID
        return new_id;
    }

    // operadores ( e caracteres nao alfanumericos isolados)
    Token t = Token{peek}; // Token t {peek}
    peek = ' ';

    //DEBUG: exibe o token para o caractere:
    cout << "<" << char(t.tag) << ">";

    // retorna o token para o caractere isolado
    return t;
}

void Lexer::Start(){
    while(peek != '\n'){
        Scan();
    }
}