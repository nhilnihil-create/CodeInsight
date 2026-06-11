#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i, m) cin >> a[i] >> b[i];

    vector<int> sum(n);
    rep(i, n) sum[i] = 0;

    rep(i, m) {
        sum[a[i]-1]++;
        sum[b[i]-1]++;
    }

    rep(i, n) {
        cout << sum[i] << endl;
    }

    return 0;
}