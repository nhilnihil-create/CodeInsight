#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const ll INF = 2e15;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
  string s;
  cin >> s;
  vector<bool> dir(4, false);
  rep(i,sz(s)){
    if(s[i]=='E')dir[0] = true;
    else if(s[i]=='W')dir[1] = true;
    else if(s[i]=='S')dir[2] = true;
    else dir[3] = true;
  }
  if((dir[0]&&dir[1])&&(!dir[2]&&!dir[3])){
    print("Yes");
  }
  else if((!dir[0]&&!dir[1])&&(dir[2]&&dir[3])){
    print("Yes");
  }
  else if(dir[0]&&dir[1]&&dir[2]&&dir[3]){
    print("Yes");
  }
  else{
    print("No");
  }
}