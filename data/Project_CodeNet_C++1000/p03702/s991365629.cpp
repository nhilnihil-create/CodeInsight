#include<bits/stdc++.h>

using namespace std;
#define taskname "TEST"
#define pb	push_back
typedef long double ld;
typedef long long ll;
const int maxn = 1e5 + 5;
int n ,  a , b;
int h[maxn];
ll nh[maxn];

int MinTime(ll need , ll left)
{
    int l = 0;
    int h = left;
    while(l <= h)
    {
        int mid = l + h >> 1;
        if((ll)mid * a + b * (left - mid) >= need)h = mid - 1;
        else l = mid + 1;
    }
    return l;
}

bool chk(ll nTime)
{
    int used = 0;
    for(int i = n ; i >= 1 ; --i)
    {
        int w = MinTime(h[i] - (ll)used * b , nTime);
        nTime -= w;
        used += w;
        if(nTime < 0)return 0;
    }
    return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if(fopen(taskname".INP","r"))
        freopen(taskname".INP", "r",stdin) ,
        freopen(taskname".OUT", "w",stdout);
    cin >> n >> a >> b;
    for(int i = 1 ; i <= n ; ++i)cin >> h[i];
    sort(h + 1 , h + n + 1);
    ll l = 1;
    ll h = 1e14;
    while(l <= h)
    {
        int mid = l + h >> 1;
        if(chk(mid))h = mid - 1;
        else l = mid + 1;
    }
    cout << l;
}
