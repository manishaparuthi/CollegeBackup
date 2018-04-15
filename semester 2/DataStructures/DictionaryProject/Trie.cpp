// C++ implementation of search and insert
// operations on Trie
#include <iostream>
using namespace std;
#include<cstring>
#define ALPHABET_SIZE 26
#include "dictionary.h"
// trie node
// Returns new trie node (initialized to NULLs)
Trie:: Trie()
{
    root=getNode();
}
TrieNode* Trie :: getNode(void)
{
    TrieNode *pNode =  new TrieNode();
    pNode->isEndOfWord = false;
    pNode->description="word not found";
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        pNode->children[i] = NULL;
    }
    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void Trie::insert(string key,char* meaning)
{

    TrieNode* pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        // cout<<"in for";
        //cout<<"key[i]: "<<key[i];

        int index = key[i] - 'a';
        //cout<<"in for";
        //cout<<"pCrawl->children[index]==NULL"<<pCrawl->children[index];
       // cout<<" index: "<<index;

        if (pCrawl->children[index]==NULL)
        {
           ;
            pCrawl->children[index] = getNode();
        }
        pCrawl = pCrawl->children[index];

    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
    pCrawl->description=meaning;
}

// Returns true if key presents in trie, else
// false
char* Trie :: search( string key)
{
    //char* neg="word not found";
    TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return "wordnotFound";

        pCrawl = pCrawl->children[index];
    }
    //if(pCrawl != NULL && pCrawl->isEndOfWord&&pCrawl)
        return (pCrawl->description);

}


