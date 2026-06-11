#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n,L;
  cin >> n >> L;
  vector<int> v(n);
  rep(i,n)cin >> v[i];
  int k = -1;
  rep(i,n-1)if(v[i]+v[i+1] >= L){
    k = i;
    break;
  }
  if(k < 0){
    cout << "Impossible\n";
    return 0;
  }
  cout << "Possible\n";
  for(int i = 0;i < k;i++)cout << i+1 << endl;
  for(int i = n-2;i > k;i--)cout << i+1 << endl;
  cout << k+1 << endl;
  




  return 0;
}