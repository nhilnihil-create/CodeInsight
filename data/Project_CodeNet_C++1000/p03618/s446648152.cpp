#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  string s;
  cin>>s;
  ll n=s.size();
  vector<ll> d(26);
  rep(i,n){
    d[s[i]-'a']++;
  }
  ll res=0;
  rep(i,26) res+=d[i]*(d[i]-1)/2;
  ll ans=n*(n-1)/2+1-res;
  cout<<ans<<endl;
}