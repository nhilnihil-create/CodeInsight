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
  string MAN ="ABC";
  vs S(3); rep(i,3)cin >> S[i];
  int cr = 0;
  
  while(1){
    char c = S[cr][0];
    S[cr].erase(0,1);
    if (c == 'a') cr = 0;
    else if (c == 'b') cr = 1;
    else if (c == 'c') cr = 2;
    else {cout << " error" << endl; return 0;}
    if(S[cr].size()==0) break;
  }           
  cout << MAN[cr] << endl;
  return 0;
}