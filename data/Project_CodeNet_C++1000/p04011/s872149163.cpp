#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
#define sf(x) scanf("%d",&x)
#define sfl(x) scanf("%lld",&x)
#define lli long long int
#define ll64 int64_t
#define pb push_back
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define frr(i,a) for(int i=0;i<a;i++)
#define frl(i,a) for(lli i=0;i<a;i++)
int main()
{
    lli n,k,x,y;
    cin>>n>>k>>x>>y;
    if(n<=k)
    {
        cout<<n*x<<endl;
    }
    else
    {
        cout<<k*x+(n-k)*y<<endl;
    }
}
