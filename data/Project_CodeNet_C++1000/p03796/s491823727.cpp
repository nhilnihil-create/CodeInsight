#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    int x; cin >> x;
    ll res = 1;
    for (int i=1;i<=x;i++) res = res*i%1000000007;
    cout << res << endl;
}
