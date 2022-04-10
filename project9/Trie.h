// File name: Trie.h
// Author: Chengye Hao
// Userid: haoc2
// Email: chengye.hao@vanderbilt.edu
// Class: 2201
// Assignment Number: PA09
// Description: The Trie class stores the word inserted in the main program or from a file,
// and has function to print these words.
// Honor Statement: I did not give or receive any help from other sources on this assignment.
// Last Changed: 2021/12/1

#ifndef PROJECT9_TRIE_H
#define PROJECT9_TRIE_H

#include "TrieNode.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <exception>

class Trie {

private:

    TrieNode root;

public:

    //The constructor of Trie class that initializes root
    Trie( );

    //pre: str is a non-empty string with lower case characters
    //The insert function that adds a word to the Trie
    void insert (const std::string& word);

    //pre: filename is the file contains words that could be inserted to the Trie
    //This function insert words to the Trie from an input file
    void loadFromFile (const std::string& filename);

    //pre: str is a string of characters in any case
    //post: return whether lower-cased word str is in the Trie
    //The function detects whether the word str is in the Trie and returns
    //a boolean as result
    [[nodiscard]] bool isWord (const std::string& word) const;

    //pre: pre is a string of characters in any case
    //post: return whether lower-cased pre is a prefix of a word in the Tire
    //This function detects whether a word in the Trie has a prefix pre
    [[nodiscard]] bool isPrefix (const std::string& pre) const;

    //This function prints all words in the Trie of this TrieNode
    void print ( ) const;

    //post: return the number of words in the Trie
    //This function counts and returns how many words are there in the Trie
    [[nodiscard]] size_t wordCount ( ) const;

};


#endif //PROJECT9_TRIE_H
