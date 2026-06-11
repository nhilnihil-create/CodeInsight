#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int main()
{
int n,i;
string s;
set<int>s1;
cin>>s;
n=s.size();
for(i=0;i<n;++i){
    s1.insert(s[i]);
}
if(s1.size()==n){
    printf("yes\n");
}
else{
    printf("no");
}


    return 0;
}
