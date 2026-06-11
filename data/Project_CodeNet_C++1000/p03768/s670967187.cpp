#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
#define zeros(x) x^(x-1)&x
#define pii pair<ll,ll>
#define cd complex<double>
#define dbg(x) cerr<<x<<endl;
#define Nmax 500005
using namespace std;

ll n, ans[Nmax], viz[Nmax], q, m, x, y;
vector<int> v[Nmax];
struct lol{
    int nod, d, c;
}a[Nmax];

void solve(int nod, int d, int c){
    if (viz[nod] >= d) return;
    if (!viz[nod]) ans[nod] = c;
    viz[nod] = d;
    for (auto it : v[nod]){
        solve(it, d-1, c);
    }
}

int main()
{
    cin >> n >> m;
    for (int i=1;i<=m;i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cin >> q;
    for (int i=1;i<=q;i++){
        cin >> a[i].nod >> a[i].d >> a[i].c;
    }
    for (int i=q;i>=1;i--){
        solve(a[i].nod, a[i].d+1, a[i].c);
    }

    for (int i=1;i<=n;i++) cout << ans[i] << '\n';


    return 0;
}
