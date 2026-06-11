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
  int N; cin >> N;
  string S; cin >> S;
  int ans = 0;
  int sum=0;
  rep(i,N){
    if(S[i]=='I'){
      sum++;
      ans = max(ans, sum);
    }
    else if(S[i]=='D') sum--;  
  }
  cout << ans << endl;
}
