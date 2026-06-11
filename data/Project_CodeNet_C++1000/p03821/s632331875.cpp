#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define rep2(i,a,n) for(int i=(a); i<(int)(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vll = vector<ll>;
using pii = pair<int, int>;
using psi = pair<string, int>;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};
//const ll mod = 1e9+7;
int gcd(int a, int b){if(a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a * b / gcd(a, b);}

ll N, M, K, H, W, L, R;
string S, T;

int main(){
  cin >> N;
  vll A(N), B(N);
  rep(i,N) cin >> A[i] >> B[i];
  ll ans = 0;
  for(int i=N-1; i>=0; --i){
    if( (A[i]+ans)%B[i] == 0) continue;
    ans += B[i] - (A[i]+ans)%B[i];
  } 
  cout << ans << endl;
  return 0;
}