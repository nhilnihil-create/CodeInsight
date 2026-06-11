#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define o(a) cout << a << endl
#define int long long
using namespace std;
typedef pair<int, int> P;

int nd[100010];//同じ数字が何個あるか
int rd[100010];//nmodmが何個あるか
int rc[100010];//nmodmを何個余るか

signed main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i];
        nd[a[i]]++;
        rd[a[i] % m]++;
    }
    int ans = 0;
    // rep(i, 0, 10){
    //     cout << i << rd[i] << endl;
    // }

    rep(i, 0, m / 2 + 1){
        int ot = (m - i) % m;
        if(ot == i){
            rc[i] = rd[i] % 2;
            ans += rd[i] / 2;
        }else{
            int tmp = min(rd[i], rd[ot]);
            ans += tmp;
            rc[i] = rd[i] - tmp;
            rc[ot] = rd[ot] - tmp;
        }
        // cout << i << " " << ans << endl;
    }
    rep(i, 0, 100010){
        if(nd[i] >= 2 && rc[i % m] >= 2){
            int tmp = min(nd[i] / 2, rc[i % m] / 2);
            ans += tmp;
            rc[i % m] -= 2 * tmp;
        }
    }
    o(ans);
}