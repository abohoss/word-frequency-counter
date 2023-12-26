#include "LLRB.hpp"
#include "main.hpp"
#include <sstream>
int main()
{
    LLRB tree;
    string filepath = "eng_news_2005_100K-sentences.txt";
    tokenizeAndInsert(filepath, tree);
    cout << tree << endl;
    return 0;
}
