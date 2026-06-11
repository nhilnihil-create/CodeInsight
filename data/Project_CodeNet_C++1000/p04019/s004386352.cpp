#include <bits/stdc++.h>
using namespace std;
string s;
bool b=true;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>s;
map<char,int>mp;
for(auto ss:s)mp[ss]++;
if(mp['N']==0&&mp['S']!=0)b=false;
if(mp['S']==0&&mp['N']!=0)b=false;
if(mp['W']==0&&mp['E']!=0)b=false;
if(mp['E']==0&&mp['W']!=0)b=false;
if(b)cout<<"Yes";
else cout<<"No";
return 0;
}
