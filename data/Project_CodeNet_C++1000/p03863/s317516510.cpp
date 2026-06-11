#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
main(){
    string s;
    cin>>s;
    int ans=0;
    int len=s.length();
    int a=0,b=0;
    if(len&1)a=1;
    if(s[0]==s[len-1])b=1;
    if(a+b==1)puts("First");
    else puts("Second");
}
