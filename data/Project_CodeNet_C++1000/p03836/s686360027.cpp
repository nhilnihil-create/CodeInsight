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

int N, M, K, H, W, L, R, X;
//string S, T;

signed main(){
  string dir = "UDLR";
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx>> ty;
  tx -= sx; ty -= sy;
  
  cout << string(tx, 'R') << string(ty, 'U');
  cout << string(tx, 'L') << string(ty, 'D');
  cout << 'L'<< string(ty+1, 'U') << string(tx+1, 'R')<<'D';
  cout << 'R'<< string(ty+1, 'D') << string(tx+1, 'L')<<'U';

  cout << endl;
  return 0;
}