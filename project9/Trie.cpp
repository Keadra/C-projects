// File name: Trie.cpp
// Author: Chengye Hao
// Userid: haoc2
// Email: chengye.hao@vanderbilt.edu
// Class: 2201
// Assignment Number: PA09
// Description: This file contains definition of functions in Trie class that stores words as strings.
// Honor Statement: I did not give or receive any help from other sources on this assignment.
// Last Changed: 2021/12/1

#include "Trie.h"

//The constructor of Trie class that initializes root
Trie::Trie(): root(' ', false) {
}

//pre: str is a non-empty string with lower case characters
//The insert function that adds a word to the Trie
void Trie::insert(const std::string &word) {
    root.insert(word);
}

//pre: filename is the file contains words that could be inserted to the Trie
//This function insert words to the Trie from an input file
void Trie::loadFromFile(const std::string &filename) {
    std::ifstream infile;
    infile.open(filename.c_str());
    if(infile.fail()){
        throw std::invalid_argument("");
    }
    std::string word;
    while (infile >> word){
        insert(word);
    }
    infile.close();
}

//pre: str is a string of characters in any case
//post: return whether lower-cased word str is in the Trie
//The function detects whether the word str is in the Trie and returns
//a boolean as result
bool Trie::isWord(const std::string &word) const {
    return root.isWord(word);
}

//pre: pre is a string of characters in any case
//post: return whether lower-cased pre is a prefix of a word in the Tire
//This function detects whether a word in the Trie has a prefix pre
bool Trie::isPrefix(const std::string &pre) const {
    return root.isPrefix(pre);
}

//This function prints all words in the Trie of this TrieNode
void Trie::print() const {
    root.print("");
}

//post: return the number of words in the Trie
//This function counts and returns how many words are there in the Trie
size_t Trie::wordCount() const {
    return root.wordCount();
}
