#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
  
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
  
using namespace std;
  
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
  
const int INF=1<<29;
const double EPS=1e-9;
  
const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

const int mod = 1e9 + 7;

ll f(vector<ll> &X) {
  int N = X.size();
  ll sum = 0;
  for (int k = 1; k <= N; k++) {
    sum += (k - 1) * X[k - 1] - (N - k) * X[k - 1];
    sum %= mod;
  }
  return sum;
}

int main() {
  // 考察1. xとyを独立にする！
  // \sum_i,j \sum_k,l (x_j - x_i) * (y_l - y_k)
  // = \sum_i,j (x_j - x_i) * \sum_k,l (y_l - y_k)
  // 考察2. \sum式は、足す順番を工夫してみる
  // x_k　は k - 1 回足され、 n - k 回引かれる
  // \sum_k ((k - 1)x_k - (n - k)x_k)

  int N, M;
  cin >> N >> M;
  vector<ll> X(N), Y(M);
  for (int i = 0; i < N; i++) {
    cin >> X[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> Y[i];
  }
  cout << (f(X) * f(Y)) % mod << endl;

  return 0;
}