#include <unordered_map>
#include <string>
#include <sstream>
using std::stringstream;
using std::unordered_map;
using std::string;

enum Tag {NUM = 256, ID, TRUE, FALSE};

struct Token{
    int tag;
    Token() : tag(0){}
    Token(int t):tag(t){}
    virtual string toString(){stringstream ss; ss << char(tag); return ss.str();}
};

struct Num : public Token{
    int value;
    Num(): Token(Tag::NUM), value(0) {}
    Num(int v): Token(Tag::NUM), value(v) {}
     virtual string toString(){stringstream ss; ss << value; return ss.str();}
};

struct Id:public Token{
    string name;
    Id(): Token(Tag::ID) {}
    Id(int t, string s):Token(t), name(s) {}
    virtual string toString() {return name;}
};

class Lexer{
    private:
    //guarda ultimo token retornado
        struct{
            Token t;
            Num n;
            Id i;
        }token; //por isso que temos varios construtores vazios.

        int line = 1;
        char peek;
        unordered_map<string, Id> id_table;
    public:
        Lexer();
        int Lineno();
        Token * Scan(); //scan retornara um ponteiro para um dos elementos do utlimo token achado
};