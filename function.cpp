#include "main.hpp"
void cleanString(string &str)
{
    for (int i = 0, len = str.size(); i < len; i++)
    {
        if (ispunct(str[i]))
        {
            str.erase(i--, 1);
            len = str.size();
        }

        str[i] = tolower(str[i]);
    }
}

template <typename K, typename V>
void tokenizeAndInsert(string &str, LLRB<K, V> &aLLRB)
{
    string word;
    istringstream stream(str);

    while (getline(stream, word, ' '))
    {
        if (word != "")
        {
            aLLRB.insert(word);
        }
    }
}
