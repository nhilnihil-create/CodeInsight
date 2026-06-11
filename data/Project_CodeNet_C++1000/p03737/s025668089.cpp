#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  string s,t,u;
  cin>>s>>t>>u;
  string S,T;
  S="abcdefghijklmnopqrstuvwxyz";
  T="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for(ll i=0;i<26;i++) {
if(S[i]==s[0]) {
cout<<T[i];
}
  }
     for(ll i=0;i<26;i++) {
if(S[i]==t[0]) {
cout<<T[i];
}
     }
        for(ll i=0;i<26;i++) {
if(S[i]==u[0]) {
cout<<T[i];
}
        }
          
          cout<<endl;
        }
