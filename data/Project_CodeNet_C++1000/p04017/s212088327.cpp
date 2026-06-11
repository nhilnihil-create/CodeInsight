#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 3000005;
const int maxm = maxn*2;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;

int f[100005][31];
int a[100005];
int n,l,q;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>a[i];
    cin>>l>>q;
    for(int i = 1;i<=n;i++) f[i][0] = upper_bound(a+1,a+n+1,a[i]+l) - a - 1;
    for(int j = 1;j<=30;j++) for(int i = 1;i<=n;i++) f[i][j] = f[f[i][j-1]][j-1];
    while(q--) {
        int x,y; cin>>x>>y; if(x>y) swap(x,y);
        int pos = x,ans = 0;
        for(int i = 30;i>=0;i--) {
            if(f[pos][i] < y) {
                ans += 1<<i; pos = f[pos][i];
            }
        }
        cout<<ans + 1<<'\n';
    }
    return 0;
}