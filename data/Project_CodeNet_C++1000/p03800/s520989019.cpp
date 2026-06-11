#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<char> ans(n);
  bool flag1 = false;
  bool flag2 = false;
  ans[0] = 'S';
  ans[1] = 'S';
  rep(i,1,n-1){
    if(s[i] == 'o'){
      if((ans[i-1] == 'S' && ans[i] == 'W') || (ans[i-1] == 'W' && ans[i] == 'S')){
        ans[i+1] = 'W';
      }
      else if((ans[i-1] == 'W' && ans[i] == 'W') || (ans[i-1] == 'S' && ans[i] == 'S')){
        ans[i+1] = 'S';
      }
    }
    else if(s[i] == 'x'){
      if((ans[i-1] == 'S' && ans[i] == 'W') || (ans[i-1] == 'W' && ans[i] == 'S')){
        ans[i+1] = 'S';
      }
      else if((ans[i-1] == 'W' && ans[i] == 'W') || (ans[i-1] == 'S' && ans[i] == 'S')){
        ans[i+1] = 'W';
      }
    }
  }
  if(s[n-1] == 'o' && ans[n-1] == 'S') if(ans[n-2] == ans[0]) flag1 = true;
  if(s[n-1] == 'o' && ans[n-1] == 'W') if(ans[n-2] != ans[0]) flag1 = true;
  if(s[n-1] == 'x' && ans[n-1] == 'S') if(ans[n-2] != ans[0]) flag1 = true;
  if(s[n-1] == 'x' && ans[n-1] == 'W') if(ans[n-2] == ans[0]) flag1 = true;
  if(s[0] == 'o' && ans[0] == 'S') if(ans[n-1] == ans[1]) flag2 = true;
  if(s[0] == 'o' && ans[0] == 'W') if(ans[n-1] != ans[1]) flag2 = true;
  if(s[0] == 'x' && ans[0] == 'S') if(ans[n-1] != ans[1]) flag2 = true;
  if(s[0] == 'x' && ans[0] == 'W') if(ans[n-1] == ans[1]) flag2 = true;
  if(flag1 && flag2){
    rep(i,0,n) cout << ans[i];
    return 0;
  }
  flag1 = false;
  flag2 = false;
  ans[0] = 'S';
  ans[1] = 'W';
  rep(i,1,n-1){
    if(s[i] == 'o'){
      if((ans[i-1] == 'S' && ans[i] == 'W') || (ans[i-1] == 'W' && ans[i] == 'S')){
        ans[i+1] = 'W';
      }
      else if((ans[i-1] == 'W' && ans[i] == 'W') || (ans[i-1] == 'S' && ans[i] == 'S')){
        ans[i+1] = 'S';
      }
    }
    else if(s[i] == 'x'){
      if((ans[i-1] == 'S' && ans[i] == 'W') || (ans[i-1] == 'W' && ans[i] == 'S')){
        ans[i+1] = 'S';
      }
      else if((ans[i-1] == 'W' && ans[i] == 'W') || (ans[i-1] == 'S' && ans[i] == 'S')){
        ans[i+1] = 'W';
      }
    }
  }
  if(s[n-1] == 'o' && ans[n-1] == 'S') if(ans[n-2] == ans[0]) flag1 = true;
  if(s[n-1] == 'o' && ans[n-1] == 'W') if(ans[n-2] != ans[0]) flag1 = true;
  if(s[n-1] == 'x' && ans[n-1] == 'S') if(ans[n-2] != ans[0]) flag1 = true;
  if(s[n-1] == 'x' && ans[n-1] == 'W') if(ans[n-2] == ans[0]) flag1 = true;
  if(s[0] == 'o' && ans[0] == 'S') if(ans[n-1] == ans[1]) flag2 = true;
  if(s[0] == 'o' && ans[0] == 'W') if(ans[n-1] != ans[1]) flag2 = true;
  if(s[0] == 'x' && ans[0] == 'S') if(ans[n-1] != ans[1]) flag2 = true;
  if(s[0] == 'x' && ans[0] == 'W') if(ans[n-1] == ans[1]) flag2 = true;
  if(flag1 && flag2){
    rep(i,0,n) cout << ans[i];
    return 0;
  }
  flag1 = false;
  flag2 = false;
  ans[0] = 'W';
  ans[1] = 'S';
  rep(i,1,n-1){
    if(s[i] == 'o'){
      if((ans[i-1] == 'S' && ans[i] == 'W') || (ans[i-1] == 'W' && ans[i] == 'S')){
        ans[i+1] = 'W';
      }
      else if((ans[i-1] == 'W' && ans[i] == 'W') || (ans[i-1] == 'S' && ans[i] == 'S')){
        ans[i+1] = 'S';
      }
    }
    else if(s[i] == 'x'){
      if((ans[i-1] == 'S' && ans[i] == 'W') || (ans[i-1] == 'W' && ans[i] == 'S')){
        ans[i+1] = 'S';
      }
      else if((ans[i-1] == 'W' && ans[i] == 'W') || (ans[i-1] == 'S' && ans[i] == 'S')){
        ans[i+1] = 'W';
      }
    }
  }
  if(s[n-1] == 'o' && ans[n-1] == 'S') if(ans[n-2] == ans[0]) flag1 = true;
  if(s[n-1] == 'o' && ans[n-1] == 'W') if(ans[n-2] != ans[0]) flag1 = true;
  if(s[n-1] == 'x' && ans[n-1] == 'S') if(ans[n-2] != ans[0]) flag1 = true;
  if(s[n-1] == 'x' && ans[n-1] == 'W') if(ans[n-2] == ans[0]) flag1 = true;
  if(s[0] == 'o' && ans[0] == 'S') if(ans[n-1] == ans[1]) flag2 = true;
  if(s[0] == 'o' && ans[0] == 'W') if(ans[n-1] != ans[1]) flag2 = true;
  if(s[0] == 'x' && ans[0] == 'S') if(ans[n-1] != ans[1]) flag2 = true;
  if(s[0] == 'x' && ans[0] == 'W') if(ans[n-1] == ans[1]) flag2 = true;
  if(flag1 && flag2){
    rep(i,0,n) cout << ans[i];
    return 0;
  }
  flag1 = false;
  flag2 = false;
  ans[0] = 'W';
  ans[1] = 'W';
  rep(i,1,n-1){
    if(s[i] == 'o'){
      if((ans[i-1] == 'S' && ans[i] == 'W') || (ans[i-1] == 'W' && ans[i] == 'S')){
        ans[i+1] = 'W';
      }
      else if((ans[i-1] == 'W' && ans[i] == 'W') || (ans[i-1] == 'S' && ans[i] == 'S')){
        ans[i+1] = 'S';
      }
    }
    else if(s[i] == 'x'){
      if((ans[i-1] == 'S' && ans[i] == 'W') || (ans[i-1] == 'W' && ans[i] == 'S')){
        ans[i+1] = 'S';
      }
      else if((ans[i-1] == 'W' && ans[i] == 'W') || (ans[i-1] == 'S' && ans[i] == 'S')){
        ans[i+1] = 'W';
      }
    }
  }
  if(s[n-1] == 'o' && ans[n-1] == 'S') if(ans[n-2] == ans[0]) flag1 = true;
  if(s[n-1] == 'o' && ans[n-1] == 'W') if(ans[n-2] != ans[0]) flag1 = true;
  if(s[n-1] == 'x' && ans[n-1] == 'S') if(ans[n-2] != ans[0]) flag1 = true;
  if(s[n-1] == 'x' && ans[n-1] == 'W') if(ans[n-2] == ans[0]) flag1 = true;
  if(s[0] == 'o' && ans[0] == 'S') if(ans[n-1] == ans[1]) flag2 = true;
  if(s[0] == 'o' && ans[0] == 'W') if(ans[n-1] != ans[1]) flag2 = true;
  if(s[0] == 'x' && ans[0] == 'S') if(ans[n-1] != ans[1]) flag2 = true;
  if(s[0] == 'x' && ans[0] == 'W') if(ans[n-1] == ans[1]) flag2 = true;
  if(flag1 && flag2){
    rep(i,0,n) cout << ans[i];
    return 0;
  }
  cout << -1 << endl;
  return 0;
}