#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  vector<ll> a(1000000);
  ll i, N, sum=0;
  
  cin >> N;
  rep(i,3*N) cin >> a[i];
  
  sort(a.begin(),a.begin()+3*N,greater<ll>());
  
  
  for(i=0;i<N;i++){
    sum += a[2*i+1];
  }
  
  cout << sum;
  
}