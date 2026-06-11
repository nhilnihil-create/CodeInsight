#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main(){
    int c;
    string s,t,q;
    cin>>s>>t>>q;
    size_t a=s.length();
    size_t b=t.length();
    if(s[a-1]==t[0] && t[b-1]==q[0]) cout<<"YES\n";
    else cout<<"NO\n";
    return(0);
}