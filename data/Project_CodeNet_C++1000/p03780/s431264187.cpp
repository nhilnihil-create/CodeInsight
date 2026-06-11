#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
#define mod 998244353
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pi pair<ll,ll>
using namespace std;
const ll N=500010;

vector<ll> ar;
int dp[5001][5001];

ll func(ll idx,ll k)
{
    if(idx<0){
        if(k<=0){return 1;}
        else{return 0;}
    }
    if(k<=0){return (1<<(idx+1));}
    if(dp[idx][k]==-1)
    {
        dp[idx][k]=func(idx-1,k-ar[idx])+func(idx-1,k);
    }
    return dp[idx][k];
}

vector<bool> ans;
int dp2[5001][5001];

void func2(ll idx,ll k)
{
    if(idx<0){return;}
    if(k<0){return;}
    if(dp2[idx][k]==-1){
        dp2[idx][k]=1;
        ll wayswith=func(idx-1,k-ar[idx]);
        ll wayswithout=func(idx-1,k);
        if(wayswith!=wayswithout){ans[idx]=0;}
        func2(idx-1,k);
        func2(idx-1,k-ar[idx]);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,k;
    cin>>n>>k;
    ar.resize(n);
    for(ll i=0;i<n;++i){
        cin>>ar[i];
    }

    memset(dp,-1,sizeof(dp));
    ll lol=func(n-1,k);
    ans.resize(n,1);

    memset(dp2,-1,sizeof(dp2));
    func2(n-1,k);

    ll sum=0;
    for(ll i=0;i<n;++i){
        sum+=ans[i];
    }
    cout<<sum<<endl;

    return (0);
}
