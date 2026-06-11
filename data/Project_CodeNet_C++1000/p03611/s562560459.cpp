#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=998244353;
const int MAX=1e5+10;
const ll INF=1e18;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> cnt(100010);
    rep(i,n) {
        int a;
        cin >> a;
        ++cnt[a];
    }
    int ans=0,s=cnt[0]+cnt[1];
    repr(i,2,100010) {
        s+=cnt[i];
        ans=max(ans,s);
        s-=cnt[i-2];
    }
    cout << ans << endl;

    return 0;   
}