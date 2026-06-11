#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y; cin >> x >> y;
  if(x == 2 || y == 2){
    cout << "No" << endl;
  }else{
    if((x == 4 || x == 6 || x == 9 || x == 12) && (y == 4 || y == 6 || y == 9 || y == 12)){
      cout << "Yes" << endl;
    }else if((x == 1 || x == 3 || x == 5 || x == 7 || x == 8 || x == 10 || x == 12) && (y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12)){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}