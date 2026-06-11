#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    string s;
    cin>>s;
    int n=s.size();
    if (s[0]!=s[n-1])
    {
        if (n&1)
            cout<<"First\n";
        else
            cout<<"Second\n";
    }
    else
    {
        if (n&1)
            cout<<"Second\n";
        else
            cout<<"First\n";
    }
}