#include <bits/stdc++.h>
#define pb push_back
#define tam 5010
#define se second
#define fi first
#define pitem item*
#define forr(i,p,n) for(ll i=p;i<n;i++)
using namespace std;
typedef long long ll;
const ll MOD=1000000007 ;
ll mult(ll a,ll b, ll p=MOD){return ((a%p)*(b%p))%p;}
ll add(ll a, ll b, ll p=MOD){return (a%p + b%p)%p;}
typedef pair<ll,ll> ii;
typedef vector<vector<ll> > vvi;
typedef  double lld;
int dpiz[tam][tam],dpder[tam][tam];
int main()
{
    int n,val,Y;
    //ios::sync_with_stdio(false);.tie(0);
    scanf("%d %d",&n,&Y);
    vector<int> v;
    int ans=0;
    forr(i,0,n)
    {
        scanf("%d",&val);
        if (val>=Y)
            {
                ans++;
                continue;
            }
        v.pb(val);
    }
    n=v.size();
    ans=0;
    memset(dpiz,0,sizeof dpiz);
    memset(dpder,0,sizeof dpder);

    dpiz[0][0]=dpder[n+1][0]=1;
    int posi,num;
    forr(i,0,v.size())
    {
        num=v[i];
        for(int k=Y-1;k>=0;k--)
        {
             if (dpiz[i][k]==1)
             {
                dpiz[i+1][k]=1;
                if (k+num<Y)
                dpiz[i+1][k+num]=1;
             }
        }
    }

    for(int i=v.size();i>=1;i--)
    {
        num=v[i-1];
        for(int k=Y-1;k>=0;k--)
        {
            if (dpder[i+1][k]==1)
            {
                dpder[i][k]=1;
                if (num+k<Y)
                dpder[i][num+k]=1;
            }
        }
       
    }
    forr(i,1,n+1)
    {
        num=v[i-1];
        set<int> s;     
        forr(k,0,Y)
            if (dpiz[i-1][k]==1)
                s.insert(k);
        bool cond=0;
        forr(k,0,Y)
        {
            if (dpder[i+1][k]==1)
            {

                ll delta=(Y-num)-k;
                //<<k<<" "<<delta<<endl;
                set<int>::iterator ite=s.lower_bound(delta);
                if (ite!=s.end()&& *ite+k<Y&& *ite+num+k>=Y)
                    {
                        cond=1;
                        break;
                    }
            }
        }
        if (cond==0)
            ans++;
        //<<cond<<" respuesta\n";
    }
    printf("%d\n",ans);
}
