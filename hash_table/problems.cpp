#include <bits/stdc++.h>
using namespace std;
int count_unique_substrings(string &str)
{
    unordered_set<string>us;
    for(int i = 0 ; i < (int)str.size() ; i++)
    {
        int l = 1;
        for(int j = i ; j < (int)str.size() ; j++)
        {
            us.insert(str.substr(i,l));
            l++;
        }
    }
    return us.size();
}
int main()
{
    string str = "aaab";
    cout << count_unique_substrings(str) << "\n";
    return 0;
}