#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // CODE FESTIVAL 2017 qual A C - Palindromic Matrix
  // 4 : H/2 * W/2
  // 2 : H%2 * W/2 + H/2 * W%2
  // 1 : H%2 * W%2
  int H, W; cin >> H >> W;
  vector<string> a(H);
  REP(i, H){
    cin >> a[i];
  }
  
  vector<int> res(3, 0);
  res[0] = (H/2) * (W/2);
  res[1] = (H%2) * (W/2) + (H/2) * (W%2);
  res[2] = (H%2) * (W%2);
  
  vector<int> alp(26, 0);
  REP(i, H){
    REP(j, W){
      alp[a[i][j] - 'a']++;
    }
  }

  vector<int> ans(3, 0);
  REP(i, 26){
    ans[0] += alp[i] / 4; alp[i] %= 4;
    ans[1] += alp[i] / 2; alp[i] %= 2;
    ans[2] += alp[i];
  }
  
  if(ans[0] < res[0]){
    cout << "No" << endl;
    return 0;
  }else if(ans[0] > res[0]){
    ans[1] += (ans[0] - res[0]) * 2;
  }
  if(ans[1] < res[1]){
    cout << "No" << endl;
    return 0;
  }
  
  cout << "Yes" << endl;
}
