#include "scanner.h"
#include "parser/token.h"

using namespace std;
Scanner::Scanner()
{
}
std::vector<Token> Scanner::scan(string inString)
{
    std::vector<Token> outVector;
    for (int i = 0; i < 5; i++)
    {
        Token newToken;
        newToken.Source = inString;
        newToken.LineNumber = i;
        newToken.Lexeme = "lexema";
        newToken.identifier;
        outVector.push_back(newToken);
    }
    return outVector;
}
