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
string S, T;
signed main(){
  cin >> N >> S >> T;
  vi a;
  int i = 0;
  while (i<N){
    if(S[i] == S[i+1]){
      a.push_back(2);
      i += 2;
    }else{
      a.push_back(1);
      i++;
    }
  }
  
  int ans = 1;
  rep(i,a.size()){
    if(i==0 && a[0] == 1) ans *= 3; 
    else if(i==0 && a[0] == 2) ans *= 6;
    else if(a[i-1] == 1 && a[i] == 1){ ans *= 2; ans %= mod;}
    else if(a[i-1] == 1 && a[i] == 2){ ans *= 2; ans %= mod;}
    else if(a[i-1] == 2 && a[i] == 1){ ans *= 1; ans %= mod;}
    else if(a[i-1] == 2 && a[i] == 2){ ans *= 3; ans %= mod;}
  }
  cout << ans << endl;
  return 0;
}