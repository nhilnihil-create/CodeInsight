#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> ii;
#define F first
#define S second
#define sqr(x) (x)*(x)
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rep(i,x,y) for(int i=x;i<(y);++i)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
/* start */

signed main(){
    IOS;
    int n; cin >> n;
    vector<int> a(2*n);
    rep(i,0,2*n) cin >> a[i];
    sort(all(a));
    int ans1 = 0, ans2=0;
    for(int i = 0;i<2*n;i+=2){
        ans1+=a[i];
    }
    for(int i = 1;i+1<2*n;i+=2){
        ans2+=a[i];
    }
    cout << max(ans1,ans2) << "\n";
}