#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;cin>>s;
  ll k;cin>>k;
  rep(i, s.size()){
    if(i==s.size()-1){
      cout<<(char)((s[s.size()-1]-'a' + k)%26 + 'a');
      break;
    }

    ll need = ('z'-s[i]+1)%26;
    if(need>k)need=0;

    cout<<(char)((s[i]+need-'a')%26+'a');
    k-=need;

  }

  return 0;
}
