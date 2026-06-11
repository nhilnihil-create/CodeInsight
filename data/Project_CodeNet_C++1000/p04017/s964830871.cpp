#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
//#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int mod = 1e9 + 7;
const int N = 200000;
int f[N], invf[N], x[N], p[23][N];
int binpow(int x, int y){
    if (y == 0) return 1;
    if (y % 2) return x * binpow(x, y - 1) % mod;
    int z = binpow(x, y / 2);
    return z * z % mod;
}
int cnk(int n, int k){
    if (k > n) return 0;
    return f[n] * invf[k] % mod * invf[n - k] % mod;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
	int n, l, q;
	cin >> n;
	for (int i = 0; i < n; i++){
        cin >> x[i];
	}
	x[n] = 2e9 + 10;
	p[0][n] = n;
	int md;
    cin >> md;
	cin >> q;
	for (int i = 0; i < n; i++){
        int l = i + 1;
        int r = n;
        while(r - l > 1){
            int mid = (r + l) / 2;
            if (x[mid] - x[i] <= md){
                l = mid;
            } else{
                r = mid;
            }
        }
        p[0][i] = l;
        //cout << i << " " << l << endl;
	}
	for (int i = 1; i < 20; i++){
        p[i][n] = n;
        for (int j = 0; j < n; j++){
            p[i][j] = p[i - 1][p[i - 1][j]];
        }
	}
	while(q--){
        int s, f;
        cin >> s >> f;
        s--;
        f--;
        if (s > f) swap(s, f);
        int res = 0;
        for (int i = 19; i >= 0; i--){
            if (p[i][s] >= f) continue;
            res += (1 << i);
            s = p[i][s];
        }
        cout << res + 1 << endl;
	}
}
