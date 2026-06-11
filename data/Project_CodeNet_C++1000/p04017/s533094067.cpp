#include<bits/stdc++.h>
using namespace std;

#define int long long
int n, x[100005], l, q, test, sparse[100005][19];

int binser(int tmp){
    if(tmp > x[n]) return n + 1;
    int l1 = 1, r = n;
    while(l1 < r - 1){
        int mid = (l1 + r) >> 1;
        if(x[mid] <= tmp) l1 = mid;
        else r = mid;
    }
    if(x[r] <= tmp) l1 = r;
    return l1;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> x[i];
    cin >> l >> q;
    for(int i = 1; i <= n; i++) sparse[i][0] = binser(x[i] + l);
    //for(int i = 1; i <= n; i++) cout << sparse[i][0] << " ";
    cout << endl;
    for(int i = 0; i <= 18; i++) sparse[n + 1][i] = n + 1;
    for(int i = 1; i <= 18; i++){
        for(int j = 1; j <= n; j++){
            sparse[j][i] = sparse[sparse[j][i - 1]][i - 1];
            //cout << sparse[j][i] << " ";
        }
        //cout << endl;
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        int ans = 0;
        for(int i = 18; i >= 0; i--){
            if(sparse[a][i] <= b){
                ans += 1 << i;
                a = sparse[a][i];
            }
        }
        if(a < b) ans++;
        cout << ans << "\n";
    }
}