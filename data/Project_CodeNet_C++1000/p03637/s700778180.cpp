#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  int cnt4 = 0, cnt2 = 0, cnt1 = 0;
  REP(i, N){
    int tmp; cin >> tmp;
    if(tmp%4 == 0){
      cnt4++;
    }else if(tmp%2 == 0){
      cnt2++;
    }else{
      cnt1++;
    }
  }
  if(cnt2 != 0) cnt1++;
  if(cnt4 >= cnt1-1 && cnt4 != 0 || cnt2 == N){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}