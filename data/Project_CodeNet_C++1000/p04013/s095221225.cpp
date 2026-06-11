#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a, n;
ll arr[55], dp[55][2500][55];
ll gen(int i, int sum, int num){
    if(i==n && num && ((double)sum/(double)num) == sum/num && sum/num==a) return 1;
    if(i==n) return 0;

    ll &ret = dp[i][sum][num];
    if(~ret) return ret;

    return ret = gen(i+1, sum, num) + gen(i+1, sum+arr[i], num+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> a;
    for(int i=0; i<n; i++) cin >> arr[i];

    memset(dp, -1, sizeof dp);
    cout << gen(0, 0, 0);
    return 0;
}
