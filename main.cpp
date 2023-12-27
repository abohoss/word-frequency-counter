#include "main.hpp"

int main(void)
{
    bool gameOn = true;
    bool corpusLoaded = false;
    LLRB corpusTree;

    while (gameOn)
    {
        cout << "1. Search corpus" << endl;
        cout << "2. Most repeated in text" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            if (corpusLoaded == false)
            {
                cout << "Loading corpus..." << endl;

                string binaryFile = "corpusTree.bin";
                corpusTree.loadTree(binaryFile);
                corpusLoaded = true;
                cout << "Corpus loaded!" << endl;
            }
            searchCorpus(corpusTree);
            break;
        case 2:
            mostReapeatedInText();
            break;
        case 3:
            gameOn = false;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return (0);
}

// #include <type_traits>
// #include "LLRB.hpp"

// int main()
// {
//     LLRB tree;
//     string s = "hello";
//     tree.insert(s);
//     // Check if Node is a POD type
//     if (std::is_pod<LLRB::Node>::value)
//     {
//         std::cout << "Node is a POD type." << std::endl;
//     }
//     else
//     {
//         std::cout << "Node is not a POD type." << std::endl;
//     }

//     // Rest of your code...
// }
