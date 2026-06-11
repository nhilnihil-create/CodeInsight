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
#define mod 1000000007

int main()
{

    string o,e;
    string ans;
    cin >> o >> e;
    ll i=0, j=0;
    while(1)
    {

        if(i==o.size() && j==e.size()) break;
        ll sz=ans.size();
        if(sz%2==0)
        {

            ans.pb(o[i]);
            i++;
        }
        else
        {

            ans.pb(e[j]);
            j++;
        }
    }
    cout << ans;
}
