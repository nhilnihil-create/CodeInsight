#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=1e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false); 

    int n;
    cin >> n;
    vector<ll> a(n),b(n+1);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    rep(i,n) b[i+1]+=b[i]+a[i];
    int ans=0;
    repr(i,1,n) {
        if (a[i]>2*b[i]) ans=i;
    }
    cout << n-ans << endl;
    
    return 0;
}
