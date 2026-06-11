#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll a,b,c;
ll ans=1000000000000000;
int main(void){
    cin>>a>>b>>c;
    ans=min({abs(b*c*(a/2)-b*c*(a-a/2)),abs(c*a*(b/2)-c*a*(b-b/2)),abs(a*b*(c/2)-a*b*(c-c/2))});
    cout<<ans<<endl;

}

