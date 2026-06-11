#include <bits/stdc++.h>
#define ll long long
#define L long
#define endl "\n"
#define ___ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int freq[1000];

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ___
    
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        freq[(int)s[i]]++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (freq[(int)s[i]] % 2 != 0)
        {
            cout<< "No";
            return 0;
        }
    }
    cout<< "Yes";
    
    return 0;
}