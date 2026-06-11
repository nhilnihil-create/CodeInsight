#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e5+10,MAXM=1e6+10;
const int MOD=1e9+7,INF=~(1<<31);
const ll llINF=((1ll<<61));

ll a[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    ll maxn=llINF,tmp=0;
    for(int i=1;i<n;i++)
    {
        tmp+=a[i];
        maxn=min(maxn,abs(sum-tmp*2));
    }
    cout<<maxn;
    return 0;
}
