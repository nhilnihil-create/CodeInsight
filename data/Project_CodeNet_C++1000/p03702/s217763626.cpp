#include <bits/stdc++.h>

using namespace std;
long long n,a,b;
vector<int>v;
bool chk(long long      i){
    long long dif=a-b;
    long long cntnd=0;
    for(int j=0;j<n;j++){
        long long cr=v[j];
        cr-=b*i;
        cntnd+=(cr>0)?(cr/dif+!!(cr%dif)):0ll;
    }
    return cntnd<=i;
}
int main()
{
    ///{}
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
    cin>>n>>a>>b;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    long long l=0,r=1e9+5;
    long long ans=INT_MAX;
    while(l<=r){
        long long mid=(r-l)/2ll+l;
        if(chk(mid)){
            ans=min(ans,mid);
            r=mid-1ll;
        }else
            l=mid+1ll;
    }
    cout<<ans<<'\n';
    return 0;
}
/**
10
0 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1
1 1 0 1 1 1 1 1 1 1
1 1 1 0 1 1 1 1 1 1
1 1 1 1 0 1 1 1 1 1
1 1 1 1 1 0 1 1 1 1
1 1 1 1 1 1 0 1 1 1
1 1 1 1 1 1 1 0 1 1
1 1 1 1 1 1 1 1 0 1
1 1 1 1 1 1 1 1 1 0
*/
