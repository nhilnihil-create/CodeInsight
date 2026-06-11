#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define Task ""
#define int long long

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 5;

int N, a[maxn], A, B;

int get(int x, int y)
{
    if (x % y == 0) return x / y;
    return x / y + 1;
}

bool check(int val)
{
    vector<int> need;
    for (int i=1; i<=N; ++i){
        if (a[i] > B * val){
            need.pb(a[i] - B * val);
        }
    }
    int res = 0;
    for (auto it : need){
        res += get(it, A - B);
    }
    return res <= val;
}

signed main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("A.INP", "r")){
        freopen("A.INP", "r", stdin);
        freopen("A.OUT", "w", stdout);
    }
    if (fopen(Task".inp", "r")){
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> N >> A >> B;
    for (int i=1; i<=N; ++i) cin >> a[i];
    int l=0, r=1e9, mid;
    while (l <= r){
        mid = (l + r) / 2;
        if (!check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    cout << l;
}
