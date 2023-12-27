#include "main.hpp"
#include <fstream>
#include <sstream>
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

void tokenizeAndInsert(string &str, LLRB &aLLRB)
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

// void tokenizeAndInsert(string &filename, LLRB &tree)
// {
//     ifstream file(filename);
//     if (!file.is_open())
//     {
//         cout << "Failed to open file: " << filename << endl;
//         return;
//     }

//     string line;
//     while (getline(file, line))
//     {
//         stringstream ss(line);
//         string word;
//         while (ss >> word)
//         {
//             if (word != "")
//             {

//                 cleanString(word); // Assuming cleanString modifies the string in-place to clean it
//                 if (word == "")
//                 {
//                     continue;
//                 }
//                 tree.insert(word); // Assuming insert is a method of LLRB that inserts a word
//             }
//         }
//     }

//     file.close();
// }

void searchCorpus(LLRB &corpusTree)
{

    string word;
    cout << "Please enter a word to search for in the corpus: ";
    cin >> word;
    int wordFrequency = corpusTree.getFrequency(word);
    cout << "The word: " << word << " was repeated " << wordFrequency << " times." << endl;
}

void mostReapeatedInText()
{
    string sentence;
    LLRB tree;
    int topN;
    cout << "Hello! this is the word frequency counter please enter text here: ";
    getline(cin, sentence);
    cout << endl;
    cleanString(sentence);
    tokenizeAndInsert(sentence, tree);
    cout << "please enter how many of the most frequent words you want to see: ";
    if (cin >> topN)
    {
        tree.displayNfrequency(topN);
        cout << endl;
    }
    else
    {
        cout << "Please enter a valid number!" << endl;
        cout << "displaying top 3 words by default: ";
        tree.displayNfrequency(3);
        cout << endl;
    }
}
