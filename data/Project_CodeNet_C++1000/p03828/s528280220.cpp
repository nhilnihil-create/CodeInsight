#include <bits/stdc++.h>
#define MAXN 2550
#define pii pair<int, int>
#define ff first
#define ss second
#define ll long long
#define in_range(x, y, n) (x >= 0 and x < n and y >= 0 and y < n)
using namespace std;
const ll mod = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(false);
    ll ans = 1, n;
    map<int, int> m;
    vector<int> prime, check(1010, 1);
    cin >> n;

    for (int i=2; i<=n; i++){
        if (check[i] == 1){
            prime.push_back(i);
            for (int j=i+i;j <=n; j+=i) check[j] = 0;
        }
    }

    for (int i=2; i<=n; i++){
        int tmp = i;

        for (auto x: prime){
            if (x > tmp) break;

            while (tmp%x == 0) tmp/=x, m[x]++;
        }
    }

    for (int i=2; i<=n; i++){
        ans *= (m[i]+1);
        ans%=mod;
    }

    cout << ans << endl;
    return 0;
}