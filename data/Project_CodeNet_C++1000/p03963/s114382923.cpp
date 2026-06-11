#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
long long N,K,ans;
cin >> N >> K;
N--;
ans = K;
K--;
rep(i,N) {
  ans *= K;
}
cout << ans << endl;



return 0;
}