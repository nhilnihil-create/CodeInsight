#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#define ALL(x) (x).begin(), (x).end()
#define rt return
#define dll(x) scanf("%I64d",&x)
#define xll(x) printf("%I64d\n",x)
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repd(i,x,n) for(int i=x;i<=n;i++)
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define gbtb ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MSC0(X) memset((X), '\0', sizeof((X)))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define eps 1e-6
#define gg(x) getInt(&x)
#define db(x) cout<<"== [ "<<x<<" ] =="<<endl;
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll powmod(ll a,ll b,ll MOD){ll ans=1;while(b){if(b%2)ans=ans*a%MOD;a=a*a%MOD;b/=2;}return ans;}
inline void getInt(int* p);
const int maxn=1000010;
const int inf=0x3f3f3f3f;
/*** TEMPLATE CODE * * STARTS HERE ***/
int n;
int l;
int q;
int x[maxn];
int ne[maxn][21];

int main()
{
    //freopen("D:\\common_text\\code_stream\\in.txt","r",stdin);
    //freopen("D:\\common_text\\code_stream\\out.txt","w",stdout);
    gbtb;
    cin>>n;

    repd(i,0,n-1)
    {
        cin>>x[i];
    }
    cin>>l;
    repd(i,0,n-1)
    {
        ne[i][0]=lower_bound(x+i,x+n,x[i]+l+1)-x-1;
    }
    repd(i,0,19)
    {
        rep(j,0,n)
        {
            ne[j][i+1]=ne[ne[j][i]][i];
        }
    }
     cin>>q;
     int xx,yy;
     while(q--)
     {
        cin>>xx>>yy;
        xx--;
        yy--;
        if(xx>yy)
        {
            swap(xx,yy);
        }
        int day=0;
        for(int i=19;i>=0;i--)
        {
            if(ne[xx][i]<yy)
            {
                xx=ne[xx][i];
                day+=1<<i;
            }
        }
        cout<<day+1<<endl;
     }
    
    
    return 0;
}

inline void getInt(int* p) {
    char ch;
    do {
        ch = getchar();
    } while (ch == ' ' || ch == '\n');
    if (ch == '-') {
        *p = -(getchar() - '0');
        while ((ch = getchar()) >= '0' && ch <= '9') {
            *p = *p * 10 - ch + '0';
        }
    }
    else {
        *p = ch - '0';
        while ((ch = getchar()) >= '0' && ch <= '9') {
            *p = *p * 10 + ch - '0';
        }
    }
}

