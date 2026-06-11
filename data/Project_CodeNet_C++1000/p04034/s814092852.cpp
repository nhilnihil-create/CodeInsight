#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> red(n, 0), num(n, 1);
    red[0] = 1;
    rep(i,m) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        if(red[x]==1){
            red[y]=1;
        }
        num[x]--;
        num[y]++;
        if(num[x]==0) red[x]=0;
    }
    int ans = 0;
    rep(i,n) if(red[i]) ans++;
    cout << ans << endl;
    return 0;
}