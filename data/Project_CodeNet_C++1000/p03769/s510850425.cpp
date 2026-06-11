#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define o(a) cout << a << endl
#define int long long
#define fi first
#define se second
using namespace std;
typedef pair<int, int> P;

signed main(){
    int n, m;
    cin >> n;
    vector<int> ans;
    repb(i, 40, 0){
        if(n >= ((int)1 << i) - 1){
            m = i; n -= ((int)1 << i) - 1; break;
        }
    }
    // cout << m << " "<< n << endl;
    rep(i, 1, m + 1){
        ans. push_back(i);
    }
    repb(i, m - 1, 0){
        if(n >= ((int)1 << i)){
            // cout << n << " " << i << endl;
            n -= ((int)1 << i);
            m++;
            ans.insert(ans.begin() + i, m);
        }
    }
    cout << 2 * m << endl;
    rep(i, 0, ans.size()){
        cout << ans[i] << " ";
    }
    rep(i, 0, ans.size()){
        cout << i + 1;
        if(i != m - 1) cout << " ";
    }
    cout << endl;
}