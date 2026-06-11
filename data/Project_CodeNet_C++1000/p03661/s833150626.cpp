#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx=1e5+100;
const int INF=99999999;
const int MOD=1e9+7;
int main()
{
    int n;
    ll a,sum[maxx*2]={0};
    cin>>n;
    sum[0]=0;
    for(int i=1; i<=n; i++){
        cin>>a;
        sum[i]=sum[i-1]+a;
    }
    ll minn=abs(sum[1]*2-sum[n]);
    for(int i=2; i<n; i++){
        minn=min(minn,abs(sum[i]*2-sum[n]));
    }
    cout<<minn<<endl;
    return 0;
}