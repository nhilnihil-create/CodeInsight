#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main() {
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];

    sort(all(a));

    vector<ll> b(n,0);
    rep(i,n){
        if(i==0) b[i]=a[i];
        else b[i]=b[i-1]+a[i];
    }
    int ans=1;

    for(int i=n-2;i>=0;i--){
        if(b[i]*2>=a[i+1]) ans++;
        else break;
    }

    cout<<ans<<endl;
}

