#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double dd;
#define all(v) v.begin(),v.end()
#define endl "\n";

void fast() {

    cin.tie(0);
    cin.sync_with_stdio(0);
}
ll n,a,arr[50+9],dp[50+9][50+9][2550];
ll ans(int i,int num,int sum){
    ll &ret=dp[i][num][sum];
    if(~ret)return ret;
    if(i==n)return dp[i][num][sum]=num&&((dd)sum/(dd)num==a);


    return ret=ans(i+1,num,sum)+ans(i+1,num+1,sum+arr[i]);

}
int main() {
        fast();
        cin>>n>>a;
    for (int i = 0; i <n ; ++i) {
        cin>>arr[i];
    }
    memset(dp,-1, sizeof(dp));
    cout<<ans(0,0,0);
}
