#include "main.hpp"

int main(void)
{
    // while (true)
    // {
    string str;
    LLRB tree;
    int n;
    char c;
    cout << "Hello! this is the word frequencu counter please enter text here: ";
    getline(cin, str);
    cout << endl;
    cleanString(str);
    cout << "cleaned string: " << str << endl;
    tokenizeAndInsert(str, tree);
    cout << "tree size: " << tree.getsize() << endl;
    cout << tree << endl;
    cout << "please enter how many of the most frequent words you want to see: ";
    if (cin >> n)
    {
        tree.displayNfrequency(n);
    }
    else
    {
        cout << "Please enter a valid number!" << endl;
        cout << "displaying top 3 words: ";
        tree.displayNfrequency(3);
        cout << endl;
    }
    //     cout << "Do you want to continue y/n ";
    //     cin >> c;
    //     if (c == 'y')
    //     {
    //         continue;
    //     }
    //     else if (c == 'n')
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         cout << "please enter a valid letter!!" << endl;
    //         continue;
    //     }
    // }
    return (0);
}
