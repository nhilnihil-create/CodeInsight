#include <bits/stdc++.h>
#define rep(i, a) for(int i = 0; i < a; i++)
#define all(v) v.begin(), v.end()
#define dcout cout << fixed << setprecision(15)
#define arep(i, a) for(auto i : a)
#define F first
#define S second
#define VE vector<int>
#define pb(x) push_back(x)
#define MOD 1000000007
#define INF 10000000000
#define int long long
#define KETA(n) floor(log10(n) + 1)
using namespace std;
signed main() {
    map<int, int> m;
    m[1] = 0;
    m[2] = 2;
    m[3] = 0;
    m[4] = 1;
    m[5] = 0;
    m[6] = 1;
    m[7] = 0;
    m[8] = 0;
    m[9] = 1;
    m[10] = 0;
    m[11] = 1;
    m[12] = 0;
    int x, y;
    cin >> x >> y;
    if(m[x] == m[y])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}