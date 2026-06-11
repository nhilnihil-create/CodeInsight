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
const ll mod = 1e9+7;
int gcd(int a, int b){if(a<b) swap(a,b); if (a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a * b / gcd(a, b);}

long long N, M, K, H, W, L, R;

int main(){
  cin >> H >> W >> N;
  vi A(N); rep(i,N) cin >> A[i];
  vvi maze(H,vi(W));
  ll cnt = 0;
  ll crr = 1;
  rep(i,H){
    if(i%2 == 0){
      rep(j,W){
        maze[i][j]= crr;
        cnt++;
        if(cnt == A[crr-1]){crr++; cnt = 0;}
      }
    }else{
      for(int j=W-1; j>=0; j--){
        maze[i][j]= crr;
        cnt++;
        if(cnt == A[crr-1]) {crr++; cnt = 0;}
      }
    }
  }
  
  rep(i,H){
    rep(j,W){
      cout << maze[i][j];
      if(j != W-1) cout << " ";
    }
    cout << endl;
  }
  return 0;
}