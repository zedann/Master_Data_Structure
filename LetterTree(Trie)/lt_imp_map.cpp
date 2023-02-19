#include <bits/stdc++.h>
using namespace std;
class trie {
private:
    map<int,trie*>child;
    bool isLeaf {};
public:
    trie(){
        
    }
    void insert(string str)
    {
        trie *cur = this;
        for(int idx = 0;idx < (int) str.size() ; idx ++)
        {
            int ch = str[idx] - 'a';
            if(!cur->child.count(ch))
                cur->child[ch] = new trie();
            cur=cur->child[ch];
        }
        cur->isLeaf = true;
    }
    bool word_exist(string str)
    {
        
    }
};
int main()
{
    return 0;
}