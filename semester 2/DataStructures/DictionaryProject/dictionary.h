// C++ implementation of search and insert
// operations on Trie
#ifndef DICT
#define DICT
#include<cstring>
using namespace std;
#include <iostream>
#define ALPHABET_SIZE 26

// trie node
class TrieNode
{

    TrieNode* children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
     bool isEndOfWord;
     char description[20];//value represents the meaning of the word
    friend class Trie;


};
//extern TrieNode node;
class Trie
{
    TrieNode* root;
    public:
    Trie()
    {
        root=getNode();
    }
    TrieNode* getNode(void)
    {
    TrieNode *pNode =  new TrieNode();
    pNode->isEndOfWord = false;
   /* (pNode->description)[0]='w';
    (pNode->description)[1]='o';
    (pNode->description)[2]='r';
    (pNode->description)[3]='d';
    (pNode->description)[4]='n';
    (pNode->description)[5]='o';
    (pNode->description)[6]='t';
    (pNode->description)[7]='f';
    (pNode->description)[8]='o';
    (pNode->description)[9]='u';
    (pNode->description)[10]='n';
    (pNode->description)[11]='d';*/
    pNode->description[0]='/0';
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        pNode->children[i] = NULL;
    }
    return pNode;
    }
    void insert( char key[],char meaning[])
    {
        TrieNode* pCrawl = root;

    for (int i = 0; i < key[i]!='\0'; i++)
    {
        //cout<<"in for";
        //cout<<"key[i]: "<<key[i];

        int index = key[i] - 'a';
        //cout<<"in for";
        //cout<<"pCrawl->children[index]==NULL"<<pCrawl->children[index];
       // cout<<" index: "<<index;

        if (pCrawl->children[index]==NULL)
        {

            pCrawl->children[index] = getNode();
        }
        pCrawl = pCrawl->children[index];

    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
    for(int i=0;meaning[i]!='\0';i++)
    (pCrawl->description)[i]=meaning[i];
    }
    bool search( char key[],char meaning[])
    {

    //char* neg="word not found";
    TrieNode *pCrawl = root;

    for (int i = 0; key[i]!='\0'; i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
        {
            meaning[0]='w';
            meaning[1]='o';
            meaning[2]='r';
            meaning[3]='d';
            meaning[4]='m';
            meaning[5]='o';
            meaning[6]='t';
            meaning[7]='f';
            meaning[8]='o';
            meaning[9]='u';
            meaning[10]='n';
            meaning[11]='d';
            return false;
        }

        pCrawl = pCrawl->children[index];
    }
    if(pCrawl != NULL && pCrawl->isEndOfWord&&pCrawl)
        {
            for(int i=0;(pCrawl->description)[i]!='\0';i++)
             meaning[i]=(pCrawl->description)[i];//=meaning[i];
             return true;
        }
}
};

#endif
