#include<bits/stdc++.h>
#define mino "test"
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define matrix vector<vector<ll>>
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define Down(i,a,b) for(int i=a; i>=b; i--)
#define FOR_(i,a,b) for(int i=a; i<b; i++)
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oo 1e9

const int N = 2e5 + 5;

using namespace std;

typedef pair<ll,int> pii;


int q, n, m;
int SA[N], SB[N], TA[N], TB[N];
string S, T;

void nhap()
{
    cin >> S >> T >> q;
    n = S.size();
    m = T.size();
    S = ' ' + S;
    T = ' ' + T;
}

void xuli()
{
    FOR(i,1,n)
    {
        SA[i] = SA[i-1];
        SB[i] = SB[i-1];
        if(S[i] == 'A') SA[i]++;
        else SB[i]++;
    }

    FOR(i,1,m)
    {
        TA[i] = TA[i-1];
        TB[i] = TB[i-1];
        if(T[i] == 'A') TA[i]++;
        else TB[i]++;
    }

    FOR(i,1,q)
    {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        int H1 = (SA[v] - SA[u-1]) - (SB[v] - SB[u-1]);
        int H2 = (TA[y] - TA[x-1]) - (TB[y] - TB[x-1]);
        if((H1 - H2) % 3 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main()
{
    //freopen(mino".inp","r",stdin);
    //freopen(mino".out","w",stdout);
    turbo
    nhap();
    xuli();
}
