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

    string a,b;
    ll tf=0;
    cin >> a >> b;
    if(a.size() != b.size())
    {

        if(a.size() > b.size()) tf=1;
        else if(a.size() < b.size()) tf=2;
    }
    else
    {

        for(ll i=0; i < a.size(); i++)
        {

            ll x=a[i] - '0';
            ll y=b[i] - '0';
            if(x!=y)
            {

                if(x > y) tf=1;
                else tf=2;
                break;
            }
        }
    }
    if(tf==1) cout << "GREATER";
    else if(tf==2) cout << "LESS";
    else cout << "EQUAL";
}
