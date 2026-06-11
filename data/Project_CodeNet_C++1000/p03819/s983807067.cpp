#include <bits/stdc++.h>

#define mp make_pair
#define X first
#define Y second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FOD(i, a, b) for(int i = a; i >= b; i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int N = 3e5 + 10;
const int M = 1e5 + 10;

struct _BIT{
    int d[M];
    void update(int x, int val){
        for(; x < M; x += x & -x)
            d[x] += val;
    }
    int get(int x){
        int res = 0;
        for(; x > 0; x -= x & -x)
            res += d[x];
        return res;
    }
} bit;

int n, m;
ii a[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    FOR(i, 1, n)
        cin >> a[i].X >> a[i].Y;
    sort(a + 1, a + 1 + n, [](const ii &a, const ii &b){
            return (a.Y - a.X) < (b.Y - b.X);
         });
    int p = 0;
    FOR(d, 1, m){
        while (p < n && (a[p + 1].Y - a[p + 1].X) < d){
            p++;
            bit.update(a[p].X, 1);
            bit.update(a[p].Y + 1, -1);
        }
        int cnt = n - p;
        for(int x = d; x <= m; x += d)
            cnt += bit.get(x);
        cout << cnt << endl;
    }
    return 0;
}