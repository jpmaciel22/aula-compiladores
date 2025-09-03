#include <iostream>
#include "parser.h"
using namespace std;

int main(){
    Parser tradutor;
    try{
        tradutor.Start();
    }
    catch(SyntaxError){
        cout << "^\n";
        cout << "ERRO DE SINTAXE";
    }
    cout << endl;
}