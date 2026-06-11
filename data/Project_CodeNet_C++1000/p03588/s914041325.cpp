#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
  int N;
  cin >> N;
  int Amax = 0;
  int Bmin = INF;
  int A, B;
  rep(i, N){
    cin >> A >> B;
    Amax = max(Amax, A);
    Bmin = min(Bmin, B);
  }
  int res = 0;
  res += Amax;
  res += Bmin;
  cout << res << endl;
}