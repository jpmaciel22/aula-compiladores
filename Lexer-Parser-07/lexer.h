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

};