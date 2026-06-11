#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;


int main(){
  int n;
  cin >> n;
  map<ll, int>p;
  int ans=0;
  rep(i,n){
    ll g;
    cin >>g;
    p[g]++;
  }
  for(auto i:p){
    if(i.second%2==1)ans++;
  }
  cout << ans << endl;
}