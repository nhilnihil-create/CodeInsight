#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N, K, X, Y;
  cin >> N >> K >> X >> Y;

  if (N <= K){
    cout << X * N << endl;
  }else{
    cout << X * K + Y * (N - K) << endl;
  }
}
