// C++ implementation of search and insert
// operations on Trie
#include <iostream>
using namespace std;
#include<cstring>
#define ALPHABET_SIZE 26

// trie node
class TrieNode
{

    TrieNode* children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
     bool isEndOfWord;
     char* description;//value represents the meaning of the word
    friend class Trie;


};
class Trie
{
    TrieNode* root;
    public:
    Trie();
    TrieNode* getNode(void);
    void insert( string key,char* meaning);
    char* search( string key);
};


