#include <bits/stdc++.h>

#define rep(i,n) for(ll i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    string g;
    rep(i,s.length()){
        if(s[i]=='B') {
            if(g.length()>0) g.pop_back();
        }
        else g.push_back(s[i]); 
    }
    cout<<g;
    return 0;
}