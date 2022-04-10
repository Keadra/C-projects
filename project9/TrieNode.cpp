// File name: TrieNode.h
// Author: Chengye Hao
// Userid: haoc2
// Email: chengye.hao@vanderbilt.edu
// Class: 2201
// Assignment Number: PA09
// Description: This file contains definition of TrieNode functions, that enable the Trie to be traversed.
// Honor Statement: I did not give or receive any help from other sources on this assignment.
// Last Changed: 2021/12/1


#include "TrieNode.h"

//pre: A character between a-z and a bool of whether the node is
//the end of a word are passed
//The constructor of a TrieNode
TrieNode::TrieNode(char c, bool b): myChar(c),
                                    flag(b){
    for (auto & node : nodes) node = nullptr;

}

//pre: rhs is another TrieNode object
//The copy constructor of the TrieNode class
TrieNode::TrieNode(const TrieNode &rhs): myChar(rhs.myChar),
                                         flag(rhs.flag){
    for(size_t i=0; i < 26; ++i){
        if(rhs.nodes[i] != nullptr) {
            TrieNode(*rhs.nodes[i]);
        } else{
            nodes[i] = nullptr;
        }
    }
}

//The destructor of the TrieNode object
TrieNode::~TrieNode(){
    for(auto & node : nodes){
        if (node!= nullptr){
            delete node;
            node = nullptr;
        }
    }
}

//pre: rhs is a TrieNode object
//post: Return this TrieNode that has been assigned with rhs' value
//The assignment operator of TrieNode object
const TrieNode &TrieNode::operator=(const TrieNode &rhs) {
    if(this!=&rhs){
        TrieNode tmp(rhs);
        std::swap(myChar, tmp.myChar);
        std::swap(flag, tmp.flag);
    }
    return *this;
}

//pre: str is a non-empty string with lower case characters
//The insert function that adds a word to the TrieNode
void TrieNode::insert(const std::string &str) {

    if (str.empty()) {
        flag = true;
        return;
    }
    else {
        size_t index = tolower(str[0]) - 'a';
        if(nodes[index]== nullptr) {
            nodes[index] = new TrieNode((char )tolower((str[0])), false);
        }
        nodes[index]->insert(str.substr(1, str.length()));
    }
}

//pre: str is a string of letters in any case
//post: return whether lower-cased word str is in the Trie
//The function detects whether the word str is in the subTries and returns
//a boolean as result
bool TrieNode::isWord(const std::string &str) const {
    if(str.empty()){
        return flag;
    }else if(nodes[tolower(str[0])-'a']== nullptr){
        return false;
    } else{
        return nodes[tolower(str[0])-'a']->isWord(str.substr(1,str.length()));
    }
}

//pre: pre is a string of characters in any case
//post: return whether lower-cased pre is a prefix of a word in the Tire
//This function detects whether a word in the subTries has a prefix pre
bool TrieNode::isPrefix(const std::string &pre) const {
    if(pre.empty()){
        return true;
    }else if(nodes[tolower(pre[0])-'a']== nullptr){
        return false;
    } else{
        return nodes[tolower(pre[0])-'a']->isPrefix(pre.substr(1,pre.length()));
    }
}

//pre: str contains myChar of previous TrieNode that has been visited
//before this TieNode
//This function prints all words in the subTrie of this TrieNode
void TrieNode::print(const std::string &str) const {
    if(flag){
        std::cout << str + myChar << std::endl;
    }
    for(auto node : nodes){
        if(node != nullptr) {
            if(myChar==' '){
                node->print(str);
            } else {
                node->print(str + myChar);
            }
        }
    }
}


//post: return the number of words in the subTrie of this node
//This function counts and returns how many words are there in the subTries
size_t TrieNode::wordCount() const {
    size_t count(0);
    for (auto node : nodes) {
        if(node != nullptr){
            count += node->wordCount();
        }
    }
    if(flag){
        return 1+count;
    } else{
        return 0+count;
    }
}
