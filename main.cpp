#include <iostream>
#include "cat.h"
#include "parser/token.h"
#include "parser/scanner.h"
#include <vector>
#include <string>

using std::cout;
using std::endl;
int main()
{
    // auto c = animals::MiniCat();
    // c.meow();
    auto sc = Scanner();
    std::vector<Token> tokeni = sc.scan("gg");
    for (auto i = tokeni.begin(); i != tokeni.end(); i++)
        cout << i->LineNumber << " " << i->Source << std::endl;
    return 0;
}