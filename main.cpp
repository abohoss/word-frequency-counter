#include "main.hpp"

int main(void)
{
    string str = "hello world i am , dhfd , kdfk,?ddujfhd";
    cleanString(str);
    cout << str << endl;
    tokenizeAndInsert(str);
}
