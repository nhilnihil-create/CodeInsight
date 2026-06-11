#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

int main(){
  ll N, K; cin >> N >> K;
  vvi num(N, vi(2));
  rep(i,N) cin >> num[i][0] >> num[i][1];
  
  sort(all(num));
  ll counter = 0;
  rep(i,N){
    counter += num[i][1];
    if(counter >= K) {cout << num[i][0] << endl; return 0;}
  } 
  return 0;
}