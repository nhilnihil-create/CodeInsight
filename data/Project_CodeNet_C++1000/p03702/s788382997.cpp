#include <bits/stdc++.h>

using namespace std;

#define loop(i, n) for(int i = 0;i < int(n);i++)
#define rloop(i, n) for(int i = int(n);i >= 0;i--)
#define range(i, a, b) for(int i = int(a);i <= int(b);i++)
#define SZ(c) int(c.size())
#define ALL(c) c.begin(), c.end()
#define RALL(c) c.rbegin(), c.rend()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1, v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1, v2, v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1, v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1, v2, v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define endl '\n'

typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;
int arr[N];
int n, a, b;
int d;

bool valid(ll step) {
    ll extra = 0;
    loop(i, n) {
        if (step > arr[i] / b)continue;
        ll need = arr[i] - step * b;
        if (need <= 0)continue;
        extra += (need + d - 1) / d;
    }
    return extra <= step;
}

ll bs(ll st, ll ed) {
    while (st < ed) {
        ll mid = st + (ed - st) / 2;
        if (valid(mid))
            ed = mid;
        else
            st = mid + 1;
    }
    return st;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    //freopen("out.in", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;
    d = a - b;
    loop(i, n)cin >> arr[i];
    cout << bs(1, 1e15) << endl;

    return 0;
}
