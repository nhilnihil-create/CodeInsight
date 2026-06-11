#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // AGC003C - BBuBBBlesort!
  int N; cin >> N;
  vector<pair<int, int> > A(N, pair<int, int>());
  REP(i, N){
    int tmp; cin >> tmp;
    A[i] = {tmp, i};
  }
  sort(A.begin(), A.end());
  int ans = 0;
  for(int i = 0; i < N; i += 2){
    if(A[i].second % 2) ans++;
  }
  
  cout << ans << endl;
}