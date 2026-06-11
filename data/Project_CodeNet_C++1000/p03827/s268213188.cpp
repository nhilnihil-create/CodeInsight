#include <bits/stdc++.h>
using namespace std;
string s;
int n,x,y,m;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>n>>s;
for(int i=0;i<n;i++){
    if(s[i]=='I')x++;
    else if(s[i]=='D')x--;
    m=max(x,y);
    if(x>y)y=x;

    }
cout<<m;
return 0;}

