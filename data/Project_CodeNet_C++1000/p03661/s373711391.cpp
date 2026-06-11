/*  TAHMID RAHMAN
    DAMIAN FOREVER
     MATH LOVER
    NEVER GIVE UP
*/
#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pb push_back
#define fi first
#define se second
#define in insert
#define mp make_pair
#define GCD(a,b) __gcd(a,b);
#define endl "\n"
#define FRU freopen("out.txt","w",stdout)
#define FRO freopen("in.txt","r",stdin)
#define INFLL 9223372036854775807
#define debug 0
#define MAXN   100001
#define ar array
const int mxN=2e5;
const int MOD=1e9+7;
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
#define debugx(v) {for(auto x:v){cout<<x<<" ";}cout<<endl;}
//Don't hesitate to ask me if you don't understand my code.......Happy coding,Tahmid...;

int main()
{
    fastio;
    ll t;
    t=1;
    //cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        vector<ll>v(n);
        ll sum=0;
        for(i=0;i<n;i++)
        {
            cin>>v[i];
            sum+=v[i];
        }
        sum-=v[n-1];
        ll ans=1e18;
        if(n==2)
        {
            cout<<abs(v[0]-v[1])<<endl;
            return 0;
        }
        ll sum1=0;
        ll j=n-2;
        for(i=n-1;i>0;i--,j--)
        {
            sum1+=v[i];
            //cout<<sum<<" "<<sum1<<endl;
            ans=min(abs(sum-sum1),ans);

            sum-=v[j];
        }
        cout<<ans<<endl;



    }

}

