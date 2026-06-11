#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
#include<string.h>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define pi pair < ll,ll >
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(int i = a;i < b;i++)
#define N 300004
#define INF 1e9+7

using namespace std;

ll n,k,ar[N],ans,cnt;
ll sum[N];
ll seg[4*N];
vector < ll > vals;
map < ll,ll > mapper;

ll get_sum(ll i,ll j)
{
    if(i == 0)
        return sum[j];

    return sum[j] - sum[i-1];
}

ll query(ll low,ll high,ll pos,ll slow)
{
    if(high <= slow)
        return seg[pos];
    if(low > slow)
        return 0;

    ll mid = (low+high)/2;

    return query(low,mid,pos*2+1,slow)+query(mid+1,high,pos*2+2,slow);
}

void update(ll low,ll high,ll pos,ll slow)
{
    if(low == slow && low == high)
    {
        seg[pos]++;
        return;
    }
    if(low > slow || high < slow)
        return;

    ll mid = (low+high)/2;

    update(low,mid,pos*2+1,slow);
    update(mid+1,high,pos*2+2,slow);
    seg[pos] = seg[pos*2+1] + seg[pos*2+2];
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    rep(i,0,n)
    {
        cin >> ar[i];

        ar[i] -= k;

        if(i == 0)
            sum[i] = ar[i];
        else
            sum[i] = sum[i-1] + ar[i];

        vals.push_back(sum[i]);
    }

    vals.push_back(0);
    sort(vals.begin(),vals.end());

    rep(i,0,vals.size())
    {
        if(!mapper[vals[i]])
        {
            mapper[vals[i]] = cnt;
            cnt++;
        }
    }

    update(0,cnt,0,mapper[0]);

    rep(i,0,n)
    {
   //     cout << sum[i] << " " << mapper[sum[i]] << " " << query(0,cnt,0,mapper[sum[i]]) << endl;
        ans += query(0,cnt,0,mapper[sum[i]]);
        update(0,cnt,0,mapper[sum[i]]);
    }

    cout << ans;

    return 0;
}

