#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    cin>>s;int l=s.size();
    if(s[0]==s[l-1]) if(l&1) puts("Second");else puts("First");
    else if(!(l&1)) puts("Second");else puts("First");
    return 0;
}