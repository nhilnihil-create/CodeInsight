//C - AtCoDeer and Election Report: 
//Assunto:
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define loop(i, a, b) for(int i = a; i < b; i++)
#define loopBack(i, a, b) for(int i = a; i >= b; i--)
#define INF INT_MAX
#define LINF LLONG_MAX
#define DINF DBL_MAX
#define MAX 100050
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

ll ceil(ll a, ll b) {
    return (a + (b-1)) / b;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    ll ans, x, y, ax, ay, m;

    cin >> n;
    cin >> x >> y;
    ax = x; ay = y;
    loop(i, 1, n) {
        cin >> x >> y;
        m = max(ceil(ax, x), ceil(ay, y));
        ax = x * m;
        ay = y * m;
    }
    ans = ax + ay;
    cout << ans << "\n";
}
    