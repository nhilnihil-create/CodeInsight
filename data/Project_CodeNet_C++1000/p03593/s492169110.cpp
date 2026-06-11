#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int h,w; cin >> h >> w;
  map<char,int> mp;
  rep(i,h) rep(j,w){
    char a; cin >> a;
    mp[a]++;
  }
  int one = 0, two = 0, four = 0;
  for(auto x : mp){
    four += x.second/4;
    x.second %= 4;
    two += x.second/2;
    x.second %= 2;
    one += x.second;
  }
  bool ok = true;
  if(h%2 && w%2){
    if(one != 1) ok = false;
  }else{
    if(one != 0) ok = false;
  }
  if(four < (h/2)*(w/2)) ok = false;
  cout << (ok ? "Yes" : "No");
  cout << "\n";
  return 0;
}
