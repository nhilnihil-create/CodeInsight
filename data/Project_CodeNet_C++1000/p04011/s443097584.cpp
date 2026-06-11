#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
int N,K,X,Y;
cin >> N >> K >> X >> Y;
int ans = 0;
if (N <= K) {
    ans += N*X;
} else {
    ans += K*X;
    ans += (N-K) * Y;
}
cout << ans << endl;


return 0;
}
