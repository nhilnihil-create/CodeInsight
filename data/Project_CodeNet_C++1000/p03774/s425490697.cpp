#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n,m,ans;
    cin>>n>>m;
    vector<ll> a(n),b(n),c(m),d(m);
    for(int i=0; i<n; i++) cin>>a[i]>>b[i];
    for(int i=0; i<m; i++) cin>>c[i]>>d[i];
    
    for(int i=0; i<n; i++) {
        ll dis, tmp = 2e9;
        for(int j=0; j<m; j++) {
            dis = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if(dis < tmp) {
                tmp = dis;
                ans = j+1;
            }
        }
        cout<<ans<<"\n";
    }
}
