#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int>pa;

const int N=2e5+100;
const int mod=1e9+7;
ll a[N];
int n;
ll slove(ll f)
{
    ll sum=0,ans=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(sum*f<=0) {
            ans+=abs(f-sum);
            sum=f;
        }
      f=-f;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll ans=min(slove(1),slove(-1));
    cout<<ans<<endl;
    return 0;
}

