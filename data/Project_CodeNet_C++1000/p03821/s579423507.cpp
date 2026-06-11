#include<bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define pi pair<int,int>
#define vi vector<int>
#define pL pair<ll,ll>
#define vL vector<ll>
#define vp vector<pi>
#define vpL vector<pL>

const int MX=1000000;
const ll inf=1e9;
const ll mod=998244353;


ll a[MX], b[MX];

int main()
{

    FasterIO;


    int n;

    cin>>n;

    for(int i=1; i<=n; i++) cin>>a[i]>>b[i];

    ll sm=0;

    for(int i=n; i>=1; i--)
    {
        ll x=a[i], y=b[i];
        ll rem=(x+sm)%y;
        if(rem) sm+=(y-rem);
    }

    cout<<sm<<endl;

    return 0;
}
