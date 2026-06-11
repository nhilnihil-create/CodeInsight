#include <bits/stdc++.h>

#define fi first
#define se second
#define int long long

const int N = 100100;
const int mod = 1e9 + 7;

using namespace std;


signed main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int n;
        cin >> n;
        int cnt = 0;
        for(int i = 0; i < n; i++){
                int x;
                cin >> x;
                cnt += (x & 1);
        }
        cout << (cnt % 2 == 0 ? "YES" : "NO") << "\n";
}
