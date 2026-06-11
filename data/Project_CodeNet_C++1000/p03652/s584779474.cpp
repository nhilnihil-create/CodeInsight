#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll, ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ppi pair<pii,int>
#define pip pair<int,pii>
#define pdd pair<double, double>
#define f first
#define s second
#define MOD 1000000007
#define mkp make_pair
#define M_PI 3.14159265358979323846
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define LOR(i,l,r) for (ll i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define LORD(i,r,l) for (ll i=r;i>=l;i--)
#define INF 1000000000
#define CL(x) memset(x,0,sizeof(x))
#define DEB(x) cout << #x << " : " << x << '\n'
#define ALL(x) x.begin(), x.end()
#define SZ(x) x.size()
#define UI(x) (int)(x-'A')
#define LI(x) (int)(x-'a')
typedef long long ll;

#define MXN 305
int N, M;
int A[MXN][MXN];
bool de[MXN];
int Ans;
int now[MXN];
int cnt[MXN];

/*
greedy with good amortized complexity
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M;
    FOR(i,1,N)
    {
        FOR(j,1,M)cin>>A[i][j];
        now[i]=1;
    }
    Ans=N;

    FOR(c,1,M-1)
    {
        FOR(i,1,M)cnt[i]=0;
        int mx=0, mxi;
        FOR(i,1,N)
        {
            int ni = A[i][ now[i] ];
            cnt[ni]++;
            if( cnt[ni]>mx )
            {
                mx=cnt[ni];
                mxi=ni;
            }
        }
        Ans=min(Ans,mx);
        de[mxi]=true;
        FOR(i,1,N)
        {
            while( de[ A[i][now[i]] ] )now[i]++;
        }
    }
    cout<<Ans<<'\n';

    return 0;
}
