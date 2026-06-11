#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using LP = pair<int, int>;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const double PI=3.14159265358979323846;

int mod = 1e9+7;

int INF = 1e9+7;

int main(){
  int A, B, C;
  cin >> A >> B >> C;
  if(B-A==C-B){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }



  return 0;
}
