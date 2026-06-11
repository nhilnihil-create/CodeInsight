#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pi acos(-1.0)
#define eps 1e-9
#define ll long long
#define ull unsigned long long
#define sf scanf
#define pf printf
#define nl printf("\n")
#define ps(s) printf("%s",s.c_str())
#define inf (ll)1e15
#define mod 1000000007
#define mem(x,val) memset(x,val,sizeof x)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend() 
#define sz(x) (int)(x).size()
#define test_case int ___t;scanf("%d", &___t);for(int cs=1;cs<=___t;cs++)

using namespace __gnu_pbds;
using namespace std;

inline string str_inp(int n){char ch[n+5];sf(" %s",ch);return string(ch);}
inline string line_inp(int n)
{char ch[n+5];fgets(ch,n+5,stdin);string s=string(ch);s.pop_back();return s;}

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;


const int S=50;
ll n,a,b;
ll ncr[S+5][S+5];
ll ara[S+5];

void NcR()
{
    for(ll i=0;i<=S;i++)
    {
        for(ll j=0;j<=i;j++)
        {
            if(j==0 || j==i)ncr[i][j]=1;
            else ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
        }
    }
}

int main()
{
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //#endif
    NcR();
    while(~sf("%lld %lld %lld",&n,&a,&b))
    {
        map<ll,ll>mp;    
        for(ll i=1;i<=n;i++)sf("%lld",&ara[i]),mp[ara[i]]++;
        
        sort(ara+1,ara+n+1);
        reverse(ara+1,ara+n+1);

        ll ways=0;
        double avg;
        for(ll i=a;i<=b;i++)
        {           
            if(i==a)
            {
                double sum=0;
                for(ll j=1;j<=a;j++)sum+=ara[j];
                avg=sum/a;

                ll need=1;
                for(ll j=a-1;j>=1;j--)if(ara[j]==ara[a])need++;

                ways+=ncr[mp[ara[a]]][need];
            }
            else if(mp[ara[1]]>=i)ways+=ncr[mp[ara[1]]][i];
        }
        pf("%.10f\n%lld\n",avg,ways);
    }
    return 0;
}
 




































