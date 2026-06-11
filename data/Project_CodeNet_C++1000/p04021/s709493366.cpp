#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 2e5 + 7;
struct Fen {
int f[N];
void clear() {
    for (int i = 0; i < N; ++i) f[i] = 0;
}   
void add(int i, int x) {
    for (; i < N; i |= i + 1) 
        f[i] += x;
}   
int get(int i) {
    int ans = 0;
    for (; i >= 0; i &= i + 1, --i) ans += f[i];
    return ans;
}   
int get(int l, int r) {
    return get(r) - get(l - 1);
}   
} f;

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector <int> p(n);
    vector <int> c;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        c.app(p[i]);
    }   
    sort(all(c));

    vector <int> bad[2];
    for (int i = 0; i < n; ++i) {
        p[i] = lower_bound(all(c), p[i]) - c.begin();
        if ((i ^ p[i]) & 1) {
            bad[i & 1].app(i);
        }   
    }
    
    if (bad[0].size() != bad[1].size()) {
        cout << "LMAO" << endl;
    }   

    cout << bad[0].size() << endl;

    /*
    cout << "bad :\n";
    for (int e : bad[0])
        cout << e << ' ';
    cout << endl;
    for (int e : bad[1])
        cout << e << ' ';
    cout << endl;

    vector <int> to(n);
    for (int i = 0; i < n; ++i)
        to[i] = i;
    for (int i = 0; i < bad[0].size(); ++i) {
        to[bad[0][i]] = bad[1][i];
        to[bad[1][i]] = bad[0][i];        
    }   
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans += f.get(to[i]);
        f.add(to[i], 1);
    }   
    cout << ans << endl;
    */
}