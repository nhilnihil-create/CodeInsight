#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
// int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  string s;
  cin >> s;
  int n = s.size();
  rep(i,n-1){
    if(s[i] == s[i+1]){
      cout << i+1 << " " << i+2 << endl;
      return 0;
    }
  }
  rep(i,n-2){
    if(s[i] == s[i+2]){
      cout << i+1 << " "<< i+3 << endl;
      return 0;
    }
  }
  cout << -1 << " "<< -1 << endl;
  return 0;
}
