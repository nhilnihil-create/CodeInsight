#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const int MOD=1e9+7;


vector<pair<int,int>> vectorCnt(vector<int> a) {
    sort(a.begin(),a.end());
    int n=a.size();
    vector<pair<int,int>> b;
    int cnt=1;
    rep(i,n-1) {
            if (a[i+1]!=a[i]) {
                b.push_back(make_pair(a[i],cnt));
                cnt=1;
            } else {
                ++cnt;
            }
    }
    b.push_back(make_pair(a[n-1],cnt));
    return b;
}

int main() {
    ios_base::sync_with_stdio(false); 

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<pair<int,int>> p=vectorCnt(a);
    vector<ll> b={0,0};

    rep(i,p.size()) {
        if (p[i].second>1)  b.push_back(p[i].first);
        if (p[i].second>3) b.push_back(p[i].first); 
    }
    ll ans=b[b.size()-1]*b[b.size()-2];
    cout << ans << endl;
    return 0;
}