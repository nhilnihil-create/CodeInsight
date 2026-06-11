#include <bits/stdc++.h>

#define mp make_pair
#define X first
#define Y second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FOD(i, a, b) for(int i = a; i >= b; i--)

using namespace std;

typedef long long ll;
typedef pair <ll, ll> ii;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

int n;
ii a[N];
ll ans[N];

int main(){
    if (fopen("inp.txt", "r")){
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> a[i].X;
        a[i].Y = i;
    }
    sort(a + 1, a + 1 + n, greater<ii>());

    ll cur = INF;
    ll minPos = n + 1;
    FOR(l, 1, n){
        int r = l;
        ans[minPos] += (cur - a[l].X) * (ll) (l - 1);
        cur = a[l].X;
        while (a[l].X == a[r].X && r <= n){
            minPos = min(a[r].Y, minPos);
            r++;
        }
        l = r - 1;
    }
    if (cur > 0)
        ans[1] += cur * (ll) n;

    FOR(i, 1, n)
        cout << ans[i] << endl;

    return 0;
}

