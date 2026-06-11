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

    ll i,j,k=0,c1=0,c2=0;
    ll n;
    cin>>n;
    unsigned long long sum=0;
    vector<ll>v(3*n);
    for(i=0;i<3*n;i++)
    {
        cin>>v[i];
    }
    sort(v.rbegin(),v.rend());
    if(debug)
    {
        for(auto x:v)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    for(i=0;i<v.size();i++)
    {
        if(c1==n)
            break;
        else
        {
           if(i%2)
                sum+=v[i],c1++;


        }
    }
    cout<<sum<<endl;


    //cout<<endl;
}
