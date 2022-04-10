// File name: TrieNode.h
// Author: Chengye Hao
// Userid: haoc2
// Email: chengye.hao@vanderbilt.edu
// Class: 2201
// Assignment Number: PA09
// Description: The TrieNode class stores a single character, a flag and 26 pointers to possible
// node with next character, and linked TrieNode form a Trie.
// Honor Statement: I did not give or receive any help from other sources on this assignment.
// Last Changed: 2021/12/1

#ifndef PROJECT9_TRIENODE_H
#define PROJECT9_TRIENODE_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>

class TrieNode {
private:


    char myChar;
    bool flag;
    TrieNode* nodes[26];


public:

    //pre: A character between a-z and a bool of whether the node is
    //the end of a word are passed
    //The constructor of a TrieNode
    TrieNode(char c, bool b);

    //pre: rhs is another TrieNode object
    //The copy constructor of the TrieNode class
    TrieNode(const TrieNode& rhs);


    //The destructor of the TrieNode object
    ~TrieNode();


    //pre: rhs is a TrieNode object
    //post: Return this TrieNode that has been assigned with rhs' value
    //The assignment operator of TrieNode object
    const TrieNode& operator= (const TrieNode& rhs);

    //pre: str is a non-empty string with lower case characters
    //The insert function that adds a word to the TrieNode
    void insert(const std::string& str);

    //pre: str is a string of characters in any case
    //post: return whether lower-cased word str is in the Trie
    //The function detects whether the word str is in the subTries and returns
    //a boolean as result
    [[nodiscard]] bool isWord(const std::string& str) const;

    //pre: pre is a string of characters in any case
    //post: return whether lower-cased pre is a prefix of a word in the Tire
    //This function detects whether a word in the subTries has a prefix pre
    [[nodiscard]] bool isPrefix(const std::string& pre) const;

    //pre: str contains myChar of previous TrieNode that has been visited
    //before this TieNode
    //This function prints all words in the subTrie of this TrieNode
    void print (const std::string& str) const;

    //post: return the number of words in the subTrie of this node
    //This function counts and returns how many words are there in the subTries
    [[nodiscard]]size_t wordCount () const;

};



#endif //PROJECT9_TRIENODE_H
