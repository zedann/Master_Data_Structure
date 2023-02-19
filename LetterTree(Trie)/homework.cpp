#include <bits/stdc++.h>
using namespace std;
class trie {
private:
    static const int MAX_CHAR = 26;
    trie* child[MAX_CHAR];
    bool isLeaf {};
public:
    trie(){
        memset(child,0,sizeof(child));
    }
    void insert(string str , int idx = 0)
    {
        if(idx == (int)str.size())
        {
            isLeaf = 1;
        }else {
            int cur = str[idx] - 'a';
            if(child[cur] == 0)
                child[cur] = new trie();
            child[cur]->insert(str,idx+1);
        }
    }
    void insert_iterative(string str)
    {
        trie *cur = this;
        for(int idx = 0; idx < str.size() ; idx++)
        {
            int ch = str[idx] - 'a';
            if(!cur->child[ch])
                cur->child[ch] = new trie();
            cur = cur->child[ch];
        }
        cur->isLeaf = 1;
    }
    bool word_exists_iterative(string str)
    {
        trie*cur = this;
        for(int idx = 0; idx< str.size() ; idx ++)
        {
            int ch = str[idx] - 'a';
            if(!cur->child[ch])
                return cur->isLeaf;
            cur = cur->child[ch];
        }
        return false;
    }

    bool word_exists(string str , int idx = 0)
    {
        if(idx == (int) str.size())
            return isLeaf;
        else {
            int cur = str[idx] - 'a';
            if(!child[cur])
                return false;
            return child[cur]->word_exists(str,idx+1);
        }
    }
    bool prefix_exist(string str,int idx = 0) 
    {
        if(idx == (int)str.size())
        {
            return true;
        }else {
            int cur = str[idx] - 'a';
            if(!child[cur])
                return false;
            return prefix_exist(str,idx+1);
        }
    }
    string first_word_prefix(const string &str)
    {
        trie*cur = this;
        for(int idx  = 0 ; idx < str.size() ;idx ++)
        {
            int ch = str[idx] - 'a';
            if(!cur->child[ch])
                break;
            if(cur->child[ch]->isLeaf)
                return str.substr(0,idx+1);
            cur = cur->child[ch];
        }
        return str;
    }
    bool suffix_exists(string str)
    {
        reverse(str.begin() , str.end());
        trie*cur = this;
        for(int idx = 0 ; idx < str.size();idx++)
        {
            int ch = str[idx] - 'a';
            if(!cur->child[ch])
                return false; 

            if(cur->child[ch]->isLeaf)
                return true;
            cur = cur->child[ch];
        }
        return false;
    }
    void insert_suffix(string str , int idx = 0)
    {
        reverse(str.begin() , str.end());
        if(idx == (int)str.size())
        {
            isLeaf = 1;
        }else {
            int cur = str[idx] - 'a';
            if(child[cur] == 0)
                child[cur] = new trie();
            child[cur]->insert(str,idx+1);
        }
    }

};
int main()
{
    return 0;
}