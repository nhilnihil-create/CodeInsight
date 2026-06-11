#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int main()
{
int n,m,i,pos;
string s1,s2;
cin>>s1>>s2;
n=s1.size();
m=s2.size();
string ans(n+m+1,'-');
pos=0;
for(i=0;i<n;++i){
    ans[pos]=s1[i];
    pos+=2;
}
pos=1;
for(i=0;i<m;++i){
    ans[pos]=s2[i];
    pos+=2;
}
for(i=0;i<n+m;++i){
    cout<<ans[i];
}

    return 0;
}