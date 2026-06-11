#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

long long INF=numeric_limits<long long>::max();

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    ll n,m,ans(0);
    cin >> n >> m;
    ll mod[m],same[100001],smod[m];
    memset(mod,0,sizeof(mod));
    memset(smod,0,sizeof(smod));
    memset(same,0,sizeof(same));
    vector< ll > x(n);
    for(ll i = 0; i < n; i++)
    {
        cin >> x[i];
        same[x[i]]++;
    }
    for(ll i = 1; i <= 100000; i++)
    {
        ll a = i%m;
        mod[a]+=same[i];
        smod[a]+=same[i]/2;
    }
    ans += mod[0]/2;
    if(m%2==0)ans += mod[m/2]/2;
    for(ll i = 1; i < (m+1)/2; i++)
    {
        ll j = m-i;
        //cout << mod[i] << " " << mod[j] << endl;
        if(mod[i]==mod[j])
        {
            ans += mod[i];
        }
        else if(mod[i]>mod[j])
        {
            ans += mod[j];
            ll left = mod[i] - mod[j];
            //cout << left/2 << " " << smod[i] << endl;
            left = min(left/2,smod[i]);
            ans += left;
        }
        else
        {
            ans += mod[i];
            ll left = mod[j] - mod[i];
            left = min(left/2,smod[j]);
            ans += left;
        }
    }
    cout << ans << endl;
}