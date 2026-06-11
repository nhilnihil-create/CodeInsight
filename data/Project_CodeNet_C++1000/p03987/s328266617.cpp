#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,a,ans=0;
    cin>>n;
    ll b[n+2];
    b[0]=b[n+1]=0;
    set<ll> s;
    set<ll>::iterator itr;
    s.insert(0);
    s.insert(n+1);
    for(int i=1;i<=n;i++){
        cin>>a;
        b[a]=i;
    }
    for(int i=1;i<=n;i++){
        itr=s.lower_bound(b[i]);
        itr--;
        ans+=i*(*(s.lower_bound(b[i]))-b[i])*(b[i]-*itr);
        s.insert(b[i]);
    }
    cout <<ans<<endl;
    return 0;
}
