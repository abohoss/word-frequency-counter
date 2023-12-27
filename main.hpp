#ifndef _MAIN_HPP
#define _MAIN_HPP

#include "MaxPQ.hpp"
#include "LLRB.hpp"
#include <sstream>

void cleanString(string &str);

void tokenizeAndInsert(string &str, LLRB &aLLRB);

void searchCorpus(LLRB &corpusTree);

void mostReapeatedInText();
#endif
