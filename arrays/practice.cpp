#include <bits/stdc++.h>
using namespace std;
int main()
{
    // int n;
    // cin >> n;
    // int arr[n];
    // for(int i = 0 ; i < n ; i++)
    //     cin >> arr[i];
    // int max_value = arr[0] , scndmax;
    // for(int i = 1 ; i < n ; i++)//O(n)
    // {
    //     if(i == n - 1)
    //         scndmax = max_value;
        
    //     max_value = max(max_value,arr[i]);
    // }
    // cout << max_value << " " << scndmax << "\n";


    // for(int i = 0 ; i < n/2 ; i++)
    //     swap(arr[i] , arr[n-i-1]);
    
    // for(auto i : arr)
    //     cout << i << " ";
    // cout << "\n";

    // string s1,s2;
    // cin >> s1 >> s2;
    // for(int i = 0 ; i < max(s1.size() , s2.size()) ; i++)
    // {
    //     if(i >= s1.size())
    //         cout << s2[i];
    //     else if (i >= s2.size())
    //         cout << s1[i];
    //     else cout << s1[i] << s2[i];
    // }
    // cout << "\n";

    // int freq[501] = {0};
    // for(int i = 0 ; i < n ;i++)
    //     freq[arr[i]] = i+1;
    // int q;
    // cin >> q;
    // while (q--)
    // {
    //     int x;
    //     cin >> x;
    //     if(!freq[x]) cout << "-1" << "\n";
    //     else cout << freq[x] << "\n";
    // }

    //hard problems
    int k , n;
    cin >> k >> n;
    vector<int>v(n+1),pref(n+1);
    for(int i = 1;  i<= n;i++)
    {
        cin >> v[i];
        pref[i] = pref[i-1] + v[i];
    }
    int ans = INT_MIN ,strt = 0;

    for(int i = 1 ; i <= n - 2;i++)
    {
        int sum = pref[i+2] - pref[i-1];
        if(sum >= ans)
        {
            ans = sum;
            strt= i-1;
        }
    }
    cout << strt << " " << strt+2 << " " << ans << "\n";
    return 0;
}