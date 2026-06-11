#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int>pa;
map<pa,int>mp;
const int N=2e5+100;
int n,m;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    int pos;
    cin>>pos;
    ll ans=0;
    for(int i=2;i<=n;i++){
        int x;cin>>x;
        ans+=min(1ll*b,1ll*(x-pos)*a);
        pos=x;
    }
    cout<<ans<<endl;
    return 0;
}
