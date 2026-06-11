#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(all(v));
    int ma = v[n - 1];
    int mi = v[0];

    int ans = INT_INF;
    for(int i = mi; i <= ma; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += pow(v[j] - i, 2);
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
}
