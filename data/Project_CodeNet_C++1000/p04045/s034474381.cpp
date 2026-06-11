#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair <int, int>;
const double PI = acos(-1);
const ll MOD = 1000000007;

int main() {
  int N,K;
  cin >> N >> K;
  vector<bool> D(10, 1);
  rep(i,K){
    int x;
    cin >> x;
    D[x] = 0;
  }

  bool h = 1;
  while(h){
    int X = N;
    while(1){
      if(D[X%10] == 1){
        if(X/10 == 0){
          h=0;
          break;
        }
        else{
          X = X/10;
        }
      }
      else break;
    }
    N++;
  }

  cout << N-1 <<endl;
}
