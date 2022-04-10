// File name: main.cpp
// Author: Chengye Hao
// Userid: haoc2
// Email: chengye.hao@vanderbilt.edu
// Class: 2201
// Assignment Number: PA09
// Description: This program tests all functions in the Trie class.
// Honor Statement: I did not give or receive any help from other sources on this assignment.
// Last Changed: 2021/12/1

#include "Trie.h"
#include <iostream>

int main() {
    Trie test;

    //test print and wordCount functions with an empty Trie
    std::cout << test.wordCount() << std::endl;
    test.print();

    //test the insert function with words in different cases
    test.insert("cat");
    test.insert("cattle");
    test.insert("BIGGER");
    test.insert("BIG");

    //test the print function with insert functions
    test.print();

    //test isWord and isPrefix functions under different conditions
    std::cout << test.isWord("at") << std::endl;
    std::cout << test.isWord("CAT") << std::endl;
    std::cout << test.isWord("ca") << std::endl;
    std::cout << test.isWord("")<<std::endl;
    std::cout << test.isWord("cat") << std::endl;
    std::cout<<std::endl;

    std::cout << test.isPrefix("cat") << std::endl;
    std::cout << test.isPrefix("CAT") << std::endl;
    std::cout << test.isPrefix("ca") << std::endl;
    std::cout << test.isPrefix("c") << std::endl;
    std::cout << test.isPrefix("Bigg") << std::endl;
    std::cout << test.isPrefix("igg") << std::endl;
    std::cout << test.isPrefix("") << std::endl;

    //test wordCount after insert 4 words
    std::cout << test.wordCount() << std::endl;

    //test loadFromFile function by inserting 5 words from a text file
    test.loadFromFile("o.txt");

    //test print function again after load words from the file
    test.print();

    //test wordCount again after second insertion
    std::cout << test.wordCount() << std::endl;

    //test insert with repeated word
    test.insert("cat");

    //test for insert function with a prefix of existing word
    test.insert("ca");

    //test for isWord and isPrefix again after the insertion
    std::cout << test.isWord("ca")<<std::endl;
    std::cout << test.isPrefix("ca")<<std::endl;

    //test whether the function correctly throws an exception
    try{
        test.loadFromFile("aaaa");
        std::cout << "test for throwing exception FAIL" << std::endl;
    }catch (std::invalid_argument&){
        std::cout << "test for throwing exception PASS" << std::endl;
    }

    test.print();
    //testing for destructor and memory leak
    //size_t a = 10000000000;
    //for (size_t i = 0; i < a; ++i) {
      //  Trie test1;
        //test1.insert("testing");
        //std::cout << ".";
    //}
    //test insert with three words that is the latter one's prefix
    Trie test2;

    test2.insert("kkkkkkk");
    test2.insert("kkkkkkkkkkkkkkk");
    test2.insert("kkkkkkkkkkkkkkkkkkkkkkkkkkkkkk");


    test2.print();

    std::cout << test2.wordCount()<< std::endl;

    //test isPrefix with a word longer than inserted one
    std::cout << test2.isPrefix("kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk")<<std::endl;

    //test isWord with a word that is longer than one and shorter than another
    std::cout << test2.isWord ("kkkkkkkkkk")<<std::endl;

    //test insert, print and word count with words that have similar prefix
    test2.insert("ZZZZZZZ");
    test2.insert("kkkKKKKkkaaaaaaeeeeeee");
    test2.insert("kkkkkkaaabbbb");
    test2.insert("kkkkkkabbbbb");

    test2.print();
    std::cout << test2.wordCount()<<std::endl;
    

    return 0;
}
