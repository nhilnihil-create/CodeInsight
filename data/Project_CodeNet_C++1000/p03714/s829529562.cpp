#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define repo(i,o,n) for(int i=o;i<(int)(n);i++)
#define repm(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sperase(v,n) (v).erase(remove(all(v), n), (v).end());
#define vdelete(v) (v).erase(unique(all(v)), (v).end());
#define pb(n) push_back(n);

int n,a[100000],hoge,Fhsum[100001],Shsum[100001],ans=-1000000000000000000;
priority_queue<int,vector<int>,greater<int>> Fh;
priority_queue<int> Sh;

main() {
    cin >> n;
    rep(i,n) cin >> hoge,Fhsum[0] += hoge,Fh.push(hoge);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> hoge,Shsum[n] += hoge,Sh.push(hoge);
    rep(i,n) {
        Fh.push(a[i]);
        Fhsum[i+1] += a[i]+Fhsum[i];
        Fhsum[i+1] -= Fh.top();
        Fh.pop();
    }
    repm(i,n) {
        Sh.push(a[i]);
        Shsum[i] += a[i]+Shsum[i+1];
        Shsum[i] -= Sh.top();
        Sh.pop();
    }
    rep(i,n+1) ans = max(ans,Fhsum[i]-Shsum[i]);
    cout << ans << endl;
}