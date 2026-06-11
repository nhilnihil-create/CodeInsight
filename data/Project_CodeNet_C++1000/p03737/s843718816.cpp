#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main(){
    int a,b,c;
    string s,t,q;
    cin>>s>>t>>q;
    a='A'-'a';
    s[0]=s[0]+a;
    t[0]=t[0]+a;
    q[0]=q[0]+a;
    cout<<s[0]<<t[0]<<q[0]<<"\n";
    return(0);
}