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
//Don't hesitate to ask me if you don't understand my code.......Happy coding,Tahmid...;
int main()
{

    ll i,j,k,cb=0,ans=0;
    ll n,maxi=0,gcdxx;
    cin>>n>>k;
    vector<ll>v(n);
    for(i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]>maxi)
            maxi=v[i];
        if(i==0)
            gcdxx=v[0];
        gcdxx=GCD(gcdxx,v[i]);
    }
    if(debug)
    {
        cout<<gcdxx<<" "<<maxi<<endl;
    }
    if(k%gcdxx==0&&k<=maxi)
        cout<<"POSSIBLE"<<endl;
    else
       cout<<"IMPOSSIBLE"<<endl;

    //cout<<sum<<endl;


    //cout<<endl;
}
