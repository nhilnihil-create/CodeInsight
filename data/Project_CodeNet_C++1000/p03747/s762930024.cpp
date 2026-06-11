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
const int N = 1e5 + 7;
int n, L, T, x[N], w[N], ans[N];
int f[3];
vector <int> p[3];

int get1(int add, int j) {
    int t = add - x[j];
    if (t < 0)
        return 0;
    else            
        return t / L + 1;
}   
int get2(int add, int j) {
    int t = add - (L - x[j]);
    if (t < 0)
        return 0;
    else            
        return t / L + 1;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    f[1] = 1;
    f[2] = -1;
    cin >> n >> L >> T;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> w[i];
        p[w[i]].app(i);
    }        

    for (int i = 0; i < n; ++i) { 
        int sh = 0;

        if (w[i] == 1) {
            vector <int> &v = p[3 - w[i]];
            int l = -1;
            int r = v.size();
            while (l < r - 1) {
                int m = (l + r) >> 1;
                int j = v[m];
                if (x[j] - x[i] < 2 * T)
                    l = m;
                else
                    r = m;   
            }   
            sh += max(0ll, l - (upper_bound(all(v), i) - v.begin()) + 1);
            
            if (v.size()) {
                int add = 2 * T - 1 - (L - x[i]);
                int l = 0;
                int r = v.size();
                while (l < r - 1) {
                    int m = (l + r) >> 1;
                    if (get1(add, v[m]) == get1(add, v[0]))
                        l = m;
                    else
                        r = m;
                }            
                sh += get1(add, v[0]) * v.size() - (v.size() - r);
            }
        }
        else {
            vector <int> &v = p[3 - w[i]];
            int l = -1;
            int r = v.size();
            while (l < r - 1) {
                int m = (l + r) >> 1;
                int j = v[m];
                if (x[i] - x[j] < 2 * T)
                    r = m;
                else 
                    l = m;
            }   
            sh += max(0ll, (upper_bound(all(v), i) - v.begin()) - r);
            
            
            if (v.size()) {
                int add = 2 * T - 1 - x[i];
                int l = 0;
                int r = v.size();
                while (l < r - 1) {
                    int m = (l + r) >> 1;
                    if (get2(add, v[m]) == get2(add, v[0]))
                        l = m;
                    else
                        r = m;
                }            
                sh += get2(add, v[0]) * v.size() + (v.size() - r);
            }
        }

        int to = x[i] + T * f[w[i]];
        to = (to % L + L) % L;

        int num = i + sh * f[w[i]];
        num = (num % n + n) % n;

        ans[num] = to;
    }           
    for (int i = 0; i < n; ++i)
        cout << ans[i] << endl;
}
