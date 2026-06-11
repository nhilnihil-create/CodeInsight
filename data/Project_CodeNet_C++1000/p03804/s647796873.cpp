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
  cin >> N >> M;
  vs A(N); vs B(M);
  rep(i,N) cin >> A[i];
  rep(i,M) cin >> B[i];
  
  for(int i=0; i+M<=N; i++){
    for (int j=0; j+M<=N; j++){
      bool chk = true;
      rep(k,M){
        if(!chk) break;
        rep(l,M){
          if(A[i+k][j+l] != B[k][l]){
            chk = false;
            break;
          }
        }
      }
      if(chk){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
      
  return 0;
}