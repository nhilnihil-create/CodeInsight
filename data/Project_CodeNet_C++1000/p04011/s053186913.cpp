#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define INF 1000000000

int main() {
    int n,k,x,y,ans;
    cin >> n >> k >> x >> y;
    ans = min(k,n)*x+max(0,n-k)*y;
    cout << ans << endl;
}