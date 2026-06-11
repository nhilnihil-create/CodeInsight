#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>s;
sort(s.begin(),s.end());
for(int i=0;i<s.size();i++){
    if(s[i]==s[i+1])n++;
}
if(n>0)cout<<"no";
else cout<<"yes";
return 0;}

