#include "main.hpp"

// int main(void)
// {
//     // while (true)
//     // {
//     string str;
//     LLRB tree;
//     int n;
//     char c;
//     cout << "Hello! this is the word frequency counter please enter text here: ";
//     getline(cin, str);
//     cout << endl;
//     cleanString(str);
//     cout << "cleaned string: " << str << endl;
//     tokenizeAndInsert(str, tree);
//     cout << "tree size: " << tree.getsize() << endl;
//     cout << tree << endl;
//     cout << "please enter how many of the most frequent words you want to see: ";
//     if (cin >> n)
//     {
//         tree.displayNfrequency(n);
//     }
//     else
//     {
//         cout << "Please enter a valid number!" << endl;
//         cout << "displaying top 3 words: ";
//         tree.displayNfrequency(3);
//         cout << endl;
//     }
//     //     cout << "Do you want to continue y/n ";
//     //     cin >> c;
//     //     if (c == 'y')
//     //     {
//     //         continue;
//     //     }
//     //     else if (c == 'n')
//     //     {
//     //         break;
//     //     }
//     //     else
//     //     {
//     //         cout << "please enter a valid letter!!" << endl;
//     //         continue;
//     //     }
//     // }
//     return (0);
// }

#include <type_traits>
#include "LLRB.hpp" // Assuming this is where your Node and LLRB classes are defined

int main()
{
    LLRB tree;
    string s = "hello";
    tree.insert(s);
    // Check if Node is a POD type
    if (std::is_pod<LLRB::Node>::value)
    {
        std::cout << "Node is a POD type." << std::endl;
    }
    else
    {
        std::cout << "Node is not a POD type." << std::endl;
    }

    // Rest of your code...
}
