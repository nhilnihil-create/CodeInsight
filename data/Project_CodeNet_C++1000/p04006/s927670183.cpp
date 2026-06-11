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
    int a[2001],v[2001];
    int n,x;
    cin>>n>>x;
    ll ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        v[i]=a[i];
        ans+=a[i];
    }
    for(int i=1;i<n;i++){
        ll now=1LL*i*x;
        for(int j=0;j<n;j++)
            now+=(v[(j+i)%n]=min(v[(j+i)%n],a[j]));
        ans=min(ans,now);
    }
    cout<<ans<<endl;

    return 0;
}