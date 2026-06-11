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

#define MXN 100005
int N, A[MXN], M;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    FOR(i,1,N)cin>>A[i];
    sort( A+1, A+1+N );
    if( A[1] == A[N] )
    {
        M = A[1];
        if( M+1==N )//M+1 kinds
        {
            cout<<"Yes\n";
            return 0;
        }
        if( N/M >= 2 )
        {
            cout<<"Yes\n";
            return 0;
        }
        else cout<<"No\n";
    }
    else if( A[1]+1 == A[N] )
    {
        M = A[1];
        int P=0,K=0;
        FOR(i,1,N)
        {
            if( A[i]==M )P++;
            else break;
        }
        K=N-P;
        //cout<<P<<' '<<K<<' '<<M+1<<'\n';
        if( (M+1-P)>=1 && K>=2*(M+1-P) )
        {
            cout<<"Yes\n";
        }
        else cout<<"No\n";
    }
    else
    {
        cout<<"No"<<'\n';
    }

    return 0;
}
