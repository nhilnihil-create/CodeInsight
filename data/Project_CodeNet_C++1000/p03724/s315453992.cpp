#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){
  int n,m;
  cin >> n >> m;
  vector<ll> v(n+1,0);
  rep(i,m){
    int a,b;cin >> a >> b;
    v[a]++;
    v[b]++;
  }
  rep(i,n+1)if(v[i] & 1){
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  





  return 0;
}