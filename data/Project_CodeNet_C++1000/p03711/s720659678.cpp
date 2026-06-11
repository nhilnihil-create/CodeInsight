#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
using P = pair<int, int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef vector<ll> vi;
const int MOD = 1000000007;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
  ll x, y;
  cin >> x >> y;
  if(x==4||x==6||x==9||x==11){
    x = 4;
  }
  else if(x==2){
    x = 2;
  }
  else{
    x = 1;
  }
  if(y==4||y==6||y==9||y==11){
    y = 4;
  }
  else if(y==2){
    y = 2;
  }
  else{
    y = 1;
  }
  if(x==y){
    print("Yes");
  }
  else{
    print("No");
  }
}