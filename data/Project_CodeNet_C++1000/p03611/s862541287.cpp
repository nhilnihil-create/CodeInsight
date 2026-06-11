#include <bits/stdc++.h>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}


#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define repr1(i, n) for (int i = n; i > 0; i--)
#define FOR(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;
const ll MOD = 1000000007;
const ll INF = 100000000;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(100005,0);

    rep(i,n){
        cin >> a[i];
        b[a[i]]++;
    }

    int ans = b[0]+b[1];
    rep1(i,100000) ans = max(ans,b[i-1]+b[i]+b[i+1]);

    cout << ans << endl;

}