#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;


int main() {
  int A,B,C,D;
  cin >> A >> B>>C>>D;
  int sizeA = A*B;
  int sizeB = C*D;
  int ans = max(sizeA,sizeB);
  cout << ans << endl; 

  return 0;
}

