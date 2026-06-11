#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int n,m,a,b;
    cin >> n >> m;
    int ans[55]={};
    rep(i,m){
        cin >> a >> b;
        ans[a]++;
        ans[b]++;
    }
    rep2(i,1,n+1)cout << ans[i] << endl;
    return 0;
}