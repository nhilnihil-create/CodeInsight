#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
int main() {
  int N, K, X, Y; cin >> N >> K >> X >> Y;
  if(N<=K)    cout << N*X << endl;
  else  cout << K*X + (N-K)*Y << endl;
  
  return 0;
}