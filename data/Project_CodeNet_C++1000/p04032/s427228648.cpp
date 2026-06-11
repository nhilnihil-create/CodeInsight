#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){

string s;
cin>>s;
ll n=s.size();
if(n==2 && s[0]==s[1]){
  return cout<<1<<" "<<2,0;
}
for(int i=0;i<n-2;i++){
  if(s[i]==s[i+1]){
    return cout<<i+1<<" "<<i+2,0;
  }
  if(s[i]==s[i+2]){
    return cout<<i+1<<" "<<i+3,0;
  }
}
cout<<-1<<" "<<-1<<endl;
return 0;
}
