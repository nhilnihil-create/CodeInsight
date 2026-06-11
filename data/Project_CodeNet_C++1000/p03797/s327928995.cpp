#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#define fi first
#define se second
#define pb(i) push_back(i)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define mes(a,b) memset(a,b,sizeof(a))
#define sbs(i,j) substr(i,j)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6+10;
const int INF = 0x3f3f3f3f;
const int inf = - INF;
const int mod = 1e9+7;
const double pi = acos(-1.0);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    while(cin>>n>>m)
    {
        ll ans;
        if(n>(m/2))
            ans=m/2;
        else
        {
            ans=n;
            m-=n*2;
            ans+=m/4;
        }
        cout<<ans<<endl;
    }
    return 0;
}
