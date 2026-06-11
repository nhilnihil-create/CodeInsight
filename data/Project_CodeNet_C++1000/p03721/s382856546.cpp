#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける
using vl = vector<ll>;  // long longの1次元の型に vl という別名をつける
using vvl = vector<vl>; // long longの2次元の型に vvl という別名をつける
int MOD = 1000000007; //10^9 + 7

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// 無限大の値
const ll INF = 1LL << 60;

int main(void){
  int n;
  ll k;
  cin >> n >> k;
  vl array(100100, 0);
  rep(i, n){
    int a,b;
    cin >> a >> b;
    array[a-1] += b;
  }

  ll cnt = 0;
  rep(i, 100100){
    if(array[i]){
      cnt += array[i];
      if(cnt>=k){
        cout << i+1 << endl;
        break;
      }      
    }
  }
  return 0;
}