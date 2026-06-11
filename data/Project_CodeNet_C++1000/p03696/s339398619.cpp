#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<set<ll>>;

int main(){
  int N; cin>>N;
  string S; cin>>S;
  int L=0,R=0,l=0;
  for(auto c: S){
    if(c=='(')L++;
    else R++;
    if(L<R){
      l++;
      L++;
    }
  }
  
  rep(i,l)cout<<'(';
  cout<<S;
  rep(i,L-R)cout<<')';
  cout<<endl;
}