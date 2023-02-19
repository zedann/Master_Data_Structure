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
    bool word_exist(string str , int idx = 0)
    {
        if(idx == (int) str.size())
            return isLeaf;
        else {
            int cur = str[idx] - 'a';
            if(!child[cur])
                return false;
            return child[cur]->word_exist(str,idx+1);
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

};
int main()
{
    return 0;
}