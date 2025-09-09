#include "lexer.h"

class Parser{
    private:
        Lexer scanner;
        Token * lookahead; // lookahead agora sera o ponteiro para um token

        void Expr();
        void Term();
        void Fact();
        bool Match(int tag);

    public:
        Parser();
        void Start();
};