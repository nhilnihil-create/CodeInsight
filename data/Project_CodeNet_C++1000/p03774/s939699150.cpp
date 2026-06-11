#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1001001001;
const ll mod = 1000000007;

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    vector<int> ans(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for(int i = 0; i < m; i++) cin >> c[i] >> d[i];
    int idx = 0;
    for(int i = 0; i < n; i++){
        int tmp = INF;
        for(int j = 0; j < m; j++){
            if(tmp > abs(a[i] - c[j]) + abs(b[i] - d[j])){
                idx = j;
                tmp = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            }
        }
        ans[i] = idx;
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] + 1 << endl;
    }
}