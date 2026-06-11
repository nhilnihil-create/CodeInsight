#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

struct BIT {
    int N;
    vector<int> bit;

    void init(int _n){
        N = _n;
        bit.resize(_n+1, 0);
    }

    int getSum(int i) {  // i番目までの要素の和を求める(1-index)
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }
    void add(int i, int x) {  // i番目の要素にxを加算
        while (i <= N) {
            bit[i] += x;
            i += i & -i;
        }
    }
};

int main() {
    ll n, k, ans = 0;
    cin >> n >> k;
    vector<ll> a(n+1), pos(n+1);
    vector<P> v(n+1);
    for(int i=0;i<n;i++){
        cin >> a[i+1];
        a[i+1] -= k;
        a[i+1] += a[i];
        v[i+1] = P(a[i+1],i+1);
    }
    sort(v.begin(), v.end());
    for(int i=0;i<=n;i++){
        pos[v[i].second] = i+1;
    }
    BIT bit;
    bit.init(n+2);
    for(int i=0;i<=n;i++){
        int id = pos[i];
        ans += bit.getSum(id);
        bit.add(id, 1);
    }
    cout << ans << endl;
    return 0;
}
