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
  cin >> N;
  vi A(N);
  vi clr(8,0);
  rep(i,N){
    cin >> A[i];
    int a = A[i]/400;
    if(a>=8) clr[8]++;
    else clr[a]++;
  }
  int mn = 0;
  rep(i,8){if(clr[i]>0) mn++;}
  int mx = mn + clr[8];
  if(mn == 0) mn++;
  cout << mn << " "<< mx << endl;
  return 0;
}
