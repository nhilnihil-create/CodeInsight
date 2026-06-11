#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
    int n;
    cin>>n;
    vector<pair<ll,ll>> p(n);
    rep(i,0,n){
        int a,b;
        cin>>a>>b;
        p[i]=make_pair(a,b);
    }

    sort(p.begin(),p.end());

    ll ans=0, num=0;
    rep(i,0,n){
        ans+=p[i].first - num;
        num=p[i].first;
    }
    ans+=p[n-1].second;
    cout<<ans<<endl;
    return 0;
}