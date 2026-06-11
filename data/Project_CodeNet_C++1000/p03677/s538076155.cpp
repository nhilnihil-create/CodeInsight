#include <bits/stdc++.h>
#define dbgi(x) cout << #x << " = " << (x) << "\n";
#define dbgvi(x) cout << #x << " = "; for(int i = 0; i < (x.size()); ++i) cout << x[i] << " ";
#define mrk() cout << "HERE\n"
#define int long long
#define vi vector < int >
#define vs vector < string >
#define vii vector < vi >
#define viii vector < vii >
#define viiii vector < viii >
#define pii pair < int, int >
#define vpii vector < pii >
#define foru(i, a, b) for(int i = a; i < b; ++i)
#define ford(i, b, a) for(int i = b; i > a; --i)
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ld long double
using namespace std;

vi add1, add2;

const int inf = (int)1e15;


void addc(int c, int l, int r){
    if(l > r)return;
    add1[l] += c;
    add1[r + 1] -= c;
}

void addp(int s, int d, int l, int r){
    if(l > r)return;
    if(l == r){
        addc(s, l, r);
        return;
    }
    add1[l] += s;
    add2[l + 1] += d;
    add2[r + 1] -= d;
    add1[r + 1] += -(s + d * (r - l));
}





signed main(){
    int n, m;
    cin >> n >> m;
    vi a(n);
    foru(i, 0, n){
        cin >> a[i];
        a[i]--;
    }
    vpii e(n - 1);
    foru(i, 0, n - 1){
        e[i] = {a[i], a[i + 1]};
    }
    add1.resize(m + 1); // add constant
    add2.resize(m + 1); // add progression
    foru(i, 0, n - 1){
        int f = e[i].first;
        int s = e[i].second;
        if(f < s){
            int d = s - f;
            addc(d, 0, f);
            addc(d, s + 1, m - 1);
            addp(d, -1, f + 1, s);
        } else {
            int d = m - f + s;
            addp(d, -1, f + 1, m - 1);
            addc(d, s + 1, f);
            addp(s + 1, -1, 0, s);
        }
    }
    int cur = 0;
    foru(i, 0, m){
        cur += add2[i];
        add1[i] += cur;
    }
    vi ans(m);
    cur = 0;
    int res = inf;
    foru(i, 0, m){
        cur += add1[i];
        ans[i] = cur;
        res = min(res, ans[i]);
    }
    cout << res;
}
