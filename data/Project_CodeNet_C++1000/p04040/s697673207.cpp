#include<bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vector<int>, greater<int> >
#define ll long long
const int INF = 1e8;
const int MAXN = 3e5 + 200;
const  long double eps = 1e-16;
const long double pi = acos(-1.0);
using namespace std;

int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};
ll MOD = 1e9 + 7;
long long  per(long long x, ll step){

    long long r = 1;

    while (step){
        if (step & 1) r = (r * x ) % MOD;
        x *= x;
        x %= MOD;
        step >>= 1;
    }
    return r;
}
ll ch[MAXN], zn[MAXN];
int n, m, a, b;

void calc(){
    ch[0] = 1;
    for (int i = 1; i <= MAXN - 10; i++)
        ch[i] = ch[i - 1] * i % MOD;
    zn[MAXN - 10] = per(ch[MAXN - 10], MOD - 2);
    for (int i = MAXN - 11; i >= 0; i--){
        zn[i] = zn[i + 1] * (i + 1)  % MOD;
    }
}
ll C(int n, int m){
    return ch[n] % MOD * zn[m] % MOD * zn[n - m] % MOD;
}
void solve(){
    cin >> n >> m >> a >> b;
    calc();
    n--; m--; a--; b--;
    ll ans =C(n + m, n);
    ans %= MOD;
    int x = n - a;
    int y = b;
    while (true){

        if (y < 0) break;
        if (x > n) break;
        ll temp = C(x + y, x) * C (n - x + m - y, m - y);
        temp %= MOD;
        ans = (ans - temp + MOD) % MOD;
        x++;
        y--;
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(7);
    //freopen("inevit.in", "r", stdin);
    //freopen("inevit.out", "w", stdout);
    int step;
    step = 1;
    //cin >> step;
    for (int i = 1; i <= step; i++)
        solve();

}