#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;


signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& x : a)
        cin >> x;
    if(n == 1 && a[0] == 1){
        cout << "Yes" << endl;
        cout << 1 << endl;
        return 0;
    }
    vector<pair<int,int>> p;
    for(int i = 0; i < n; ++i)
        p.emplace_back(--a[i], i);
    sort(p.begin(), p.end());
    int c = 0;
    vector<int> ans(n * n, -1);
    for(auto& q : p){
        int pos, num;
        tie(pos, num) = q;
        for(int i = 0; i < num; ++i){
            while(ans[c] != -1){
                if(++c >= n * n){
                    cout << "No" << endl;
                    return 0;
                }
            }
            ans[c++] = num;
            if(c >= n * n){
                cout << "No" << endl;
                return 0;
            }
        }
        ans[pos] = num;
    }
    reverse(p.begin(), p.end());
    c = n * n - 1;
    while(ans[c] != -1)
        c--;
    for(auto& q : p){
        int pos, num;
        tie(pos, num) = q;
        for(int i = 0; i < n - num - 1; ++i){
            while(ans[c] != -1){
                if(--c < 0){
                    cout << "No" << endl;
                    return 0;
                }
            }
            ans[c--] = num;
            if(c < 0){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    if(count(ans.begin(), ans.end(), -1)){
        cout << "No" << endl;
        return 0;
    }
    vector<vector<int>> v(n);
    for(int i = 0; i < n * n; ++i)
        v[ans[i]].emplace_back(i);
    for(int i = 0; i < n; ++i){
        if(v[i].size() != n || v[i][i] != a[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    for(int i = 0; i < n * n - 1; ++i)
        cout << ans[i] + 1 << " ";
    cout << ans.back() + 1 << endl;
}
