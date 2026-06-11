#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n;
  cin >> n;
  vector<int> v(n);
  vector<P> k(n);
  rep(i,n){
    cin >> v[i];
    k[i] = make_pair(v[i],i);
  }
  sort(ALL(k));
  rep(i,n)v[k[i].second] = i;
  int even = 0,odd = 0;
  rep(i,n)if((i%2) != (v[i]%2)){
    if(v[i] & 1)odd++;
    else even++;
  }
  cout << abs(odd-even)+min(odd,even) << endl;

  



  return 0;
}