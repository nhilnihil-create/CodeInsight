#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double
#define zeros(x) x^(x-1)&x
#define pii pair<ll,ll>
#define cd complex<double>
#define dbg(x) cerr<<x<<endl;
#define Nmax 200005
using namespace std;

ll n, m, x, y, uz[Nmax], nr, U, A, B;
vector<ll> v[Nmax];

bool bipartit(int nod, int nr){
    bool bip = 1;
    uz[nod] = nr;
    for (auto it : v[nod]){
        if (uz[it] && uz[it]%2 == nr%2) bip = 0;
        if (uz[it]) continue;
        bip &= bipartit(it, nr+1);
    }
    return bip;
}

int main()
{
    cin >> n >> m;
    for (int i=1;i<=m;i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for (int i=1;i<=n;i++){
        if (uz[i]) continue;
        if (v[i].size()==0) U++;
        else if (bipartit(i,1)) A++;
        else B++;
    }

    ll ans = U * (n-U) * 2 + U * U;
    ans += A * A * 2;
    ans += A * B * 2 + B * B;
    cout << ans << '\n';

    return 0;
}
