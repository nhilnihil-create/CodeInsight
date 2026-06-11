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
int ans;
void chk(int H, int W){
  rep2(i,1,H){
    int a = i*W;
      
    int w = W/2;
    int b = (H-i)*w;
    int c = H*W - a - b;
    int mx = max(a, max(b, c));
    int mn = min(a, min(b, c));
    ans = min(ans, mx-mn);

    int d = (H-i)/2;
    b = d*W;
    c = H*W - a - b;
    mx = max(a, max(b, c));
    mn = min(a, min(b, c));
    ans = min(ans, mx-mn); 
  }
  return;
}

signed main(){
  cin >> H >> W; 
  if(H%3 == 0 || W%3 == 0){
    cout << 0 << endl;
    return 0;
  }
  
  ans = 1e18;
  chk(H,W);
  swap(H,W);
  chk(H,W);
  
  cout << ans << endl;
  return 0;
}