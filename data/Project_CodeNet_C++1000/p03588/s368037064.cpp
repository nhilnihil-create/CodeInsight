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
  int N; cin >> N;
  vvi s(N,vi(2));
  rep(i,N) cin >> s[i][0] >> s[i][1];
  sort(all(s)); 
  reverse(all(s));
  cout << s[0][0]+s[0][1] << endl;
  
  return 0;
}