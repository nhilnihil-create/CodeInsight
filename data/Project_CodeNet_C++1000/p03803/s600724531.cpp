#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(long long i=0; i<(int)n; i++)
#define rep2(i,a,n) for(long long i=(a); i<(int)(n); i++)
#define all(vec) vec.begin(),vec.end()
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using psi = pair<string, int>;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};
const int mod = 1e9+7;
int gcd(int a, int b){if(a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a * b / gcd(a, b);}

int N, M, K, H, W, L, R, X, A, B, C;
//string S, T;

signed main(){
  cin >> A >> B;
  if(A==B) cout << "Draw" <<endl;
  else if(A==1 && B == 13) cout << "Alice" << endl;
  else if(A==13 && B == 1) cout << "Bob" << endl;
  else if(A>B)cout << "Alice" << endl;
  else cout << "Bob" << endl;
    
  return 0;
}