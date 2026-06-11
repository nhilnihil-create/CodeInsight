#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long
#define pii pair<int, int>
#define sz(x) (int)x.size()
#define ff first
#define ss second
#define MP make_pair
#define PB emplace_back
#define all(x) (x).begin(), (x).end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int INF = 1e18L;
const double eps = 1e-9;
const int mod = 1e9 + 7;

int32_t main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    IOS;
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "1\n";
        return 0;
    }
    vector<int> fq(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int x = i;
        for (int j = 2; j * j <= x; j++)
        {
            if (x % j == 0)
            {
                int cnt = 0;
                while (x % j == 0)
                {
                    cnt++;
                    x /= j;
                }
                fq[j] += cnt;
            }
        }
        if (x > 1)
        {
            fq[x] += 1;
        }
    }
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        if (fq[i])
        {
            (ans *= fq[i] + 1) %= mod;
        }
    }
    cout << ans << "\n";
    return 0;
}