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
  
  vector<queue<char>> vec(3);
  rep(i,3){
    string s;
    cin >> s;
    int n = s.size();
    rep(j,n)vec[i].push(s[j]);
  }
  
  int now=0;
  while(true){
    if(vec[now].empty()){
      cout << char(now+'A') << endl;
      return 0;
    }
    char c=vec[now].front();
    vec[now].pop();
    now = c-'a';
  }
  return 0;
}
