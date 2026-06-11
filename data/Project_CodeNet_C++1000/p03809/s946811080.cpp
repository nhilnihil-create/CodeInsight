#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double
#define zeros(x) x^(x-1)&x
#define pii pair<ll,ll>
#define cd complex<double>
#define dbg(x) cerr<<#x<<": "<<x<<endl;ll
#define Nmax 400005
#define OFF 100001
#define MOD 1000000007
using namespace std;

ll n, x, y, A[Nmax], sav;
vector<ll> v[Nmax];

ll dfs(ll nod, ll ant){
    ll s = 0;
    vector<ll> L;
    for (auto it : v[nod]){
        if (it == ant) continue;
        L.push_back(dfs(it, nod));
        s += L.back();
    }
    if (L.empty()){
        return A[nod];
    }
    sort(L.begin(), L.end());
    ll mn = max(0LL, L.back() - (s - L.back()));
    ll up = mn;
    A[nod] -= mn;
    s -= mn;
    if (s%2) s--, up++, A[nod]--;
    ll y = A[nod] - s / 2;
    ll x = A[nod] - 2 * y;
    if (x >= 0 && y >= 0 && 2 * y + x == A[nod] && A[nod] >= 0 && x + y == s/2)
        return 2 * y+up;
    cout << "NO\n";
    exit(0);
}

int main()
{
    cin >> n;
    for (int i=1;i<=n;i++) cin >> A[i];
    for (int i=1;i<n;i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        if (v[x].size() > 1) sav = x;
        if (v[y].size() > 1) sav = y;
    }
    if (n==2){
        if (A[1] == A[2]) cout << "YES\n";
        else cout << "NO\n";
        return 0;
    }

    if (dfs(sav, -1) == 0) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
