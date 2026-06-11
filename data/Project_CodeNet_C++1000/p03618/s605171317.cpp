#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=1000000000000000000;
const long double PI=3.14159265358979;
const ll MAX=100010;

int main() {
  string s;
  cin>>s;
  ll N=s.size();
  vector<ll> A(0);
  sort(s.begin(),s.end());
  ll cnt=1;
  for(int i=0;i<N;i++){
    if(i==N-1||s[i]!=s[i+1]){
      A.push_back(cnt);
      cnt=1;
    }
    else{
      cnt++;
    }
  }
  ll ans=N*(N-1)/2+1;
  for(ll x:A){
    ans-=x*(x-1)/2;
  }
  cout<<ans;
}
