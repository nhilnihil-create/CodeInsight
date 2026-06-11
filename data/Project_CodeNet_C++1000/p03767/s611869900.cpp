#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n;
    cin >> n;
    vector<int> a(n*3);
    rep(i, n * 3) cin >> a[i];

    sort(all(a));
    reverse(all(a));
    ll ans = 0;
    for(int i = 1; i < n * 2; i+=2) {
        ans += a[i];
    }

    cout << ans << endl;

    return 0;
}