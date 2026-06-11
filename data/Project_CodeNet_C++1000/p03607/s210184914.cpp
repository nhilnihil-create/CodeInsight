#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(a) a.begin(), a.end()

const int maxn = 200010;
const int MOD = 1e9+7;
const int INF = 1e9;
const ll LINF = 1e18;
ll n, m, a[maxn];
map<int, int> M, N;
set<int> S;
string s;

void solve()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        M[a[i]]++;
    }
    int cnt=0;
    for(auto u : M)
        if(u.second%2)cnt++;
    cout << cnt;
}
//1212135 34343434343
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1; //cin >> t;
    while(t--) solve();
}
