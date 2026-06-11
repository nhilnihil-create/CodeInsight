#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n][m];
    rep(i,n) {
        rep(j,m) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    int ans = n;
    vector<bool> use(m,true); 
    rep(i,m){
        int num[m] = {};
        rep(j,n){
            int k = 0;
            while(!use[a[j][k]]){
                 k++;
            }
            num[a[j][k]]++;
        }
        int p = 0, q = -1;
        rep(j,m){
            if(num[j] > p){
                p = num[j];
                q = j;
            }
        }
        ans = min(p,ans);
        use[q] = false;
    }
    cout << ans << endl;
    return 0;
}
