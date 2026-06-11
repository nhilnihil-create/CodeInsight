#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<P> x(n);
    vector<int> ans(n*n, -1), cnt(n, 0), a(n);
    rep(i, n){
        cin >> x[i].first;
        x[i].second = i+1;
        a[i] = x[i].first;
        ans[x[i].first-1] = i+1;
    }
    sort(all(x));
    int p = 0;
    rep(i, n){
        int j = 0;
        while(j < x[i].second-1){
            if(ans[p] == -1){
                ans[p] = x[i].second;
                j++;
            }
            p++;
        }
    }
    rep(i, n){
        int j = 0;
        while(j < n-x[i].second){
            if(ans[p] == -1){
                ans[p] = x[i].second;
                j++;
            }
            p++;
        }
    }
    bool ok = true;
    rep(i, n*n){
        cnt[ans[i]-1]++;
        if(cnt[ans[i]-1] == ans[i] && i+1 != a[ans[i]-1])ok = false;
    }
    cout << (ok ? "Yes" : "No") << endl;
    if(ok){
        rep(i, n*n)cout << ans[i] << " ";
        cout << endl;
    }
}