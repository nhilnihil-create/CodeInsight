//bad_bat
#include<bits/stdc++.h>
using namespace std;

#define Fast ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define FO freopen("in.txt", "r", stdin)
#define FC freopen("out.txt", "w", stdout)
#define aise cout<<"aise"<<endl
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define ll long long
#define all(x) x.begin(), x.end()
#define mset(v, a) memset(v, a, sizeof(v))
#define pll pair< ll, ll >
#define pdd pair< double, double >
#define ff first
#define ss second
#define pi acos(-1.0)
#define mxN 2010
#define inf 1e14
#define MOD 1000000007

int main()
{

    ll s,c;
    ll ans=0;
    cin >> s >> c;
    if(s >= c)
    {

        ans=c/2;
    }
    else
    {

        if(s*2 <= c)
        {

            ans+=s;
            c-=(s*2);
            ans+=c/4;
        }
        else
        {

            ans=c/2;
        }
    }
    cout << ans;
}
