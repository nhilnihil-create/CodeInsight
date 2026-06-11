#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  string O, E;
  cin >> O >> E;

  int N = O.length();
  int M = E.length();
  if (N == M){
    for (int i = 0; i < N; i++){
      cout << O[i] << E[i];
    }
  }else{
    for (int i = 0; i < N - 1; i++){
      cout << O[i] << E[i];
    }
    cout << O[N - 1] << endl;
  }
}
