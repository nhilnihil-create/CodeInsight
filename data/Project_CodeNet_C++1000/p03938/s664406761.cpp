#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007

const int crit = 300000000;

int main(){
  
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n)cin >> a[i];
  vector<int> v(n,crit),w(n,crit);
  rep(i,n)v[i]+= i,w[i] += n-i-1;
  int cnt = 1;
  vector<int> sv(n+1,0),sw(n+1,0);
  for(int i = 1;i < n;i++){
    if(a[i-1] < a[i]){
      sv[a[i]] += cnt;
      sw[a[i]] += cnt;
      sw[n] -= cnt;
      cnt++;
    }else{
      sw[a[i]] += cnt;
      sv[a[i]] += cnt;
      sv[0] -= cnt;
      cnt++;
    }
  }
  rep(i,n)sv[i+1] += sv[i];
  for(int i = n;i > 0;i--)sw[i-1] += sw[i];
  rep(i,n)cout << v[i]+sv[i+1] << " ";
  cout << "\n";
  rep(i,n)cout << w[i]+sw[i+1] << " ";
  cout << "\n";



  return 0;
}