#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define P pair<ll,ll> 
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;cin>>s;
  ll k,pos=0,l=s.length();cin>>k;
  lvector v(l,0);
  rep(i,l) v[i]=26-(s[i]-'a');
  while(pos<l&&k>0) {
    if(s[pos]=='a') {pos++;continue;} 
    if(v[pos]>k) pos++;
    else {
       s[pos]='a';
       k-=v[pos],pos++;
    }
  }
  if(k>0) s[l-1]+=(k%26);
  print(s);
  return 0;
}