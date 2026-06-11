#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;

    int x;
    cin >> x;

    if (x == 2 && n == 2) { 
        cout << "Yes" << endl;
        cout << 1 << ' ' << 2 << ' ' << 3 << endl;
    }   
    else if (x == 1 || x == 2 * n - 1) {
        cout << "No" << endl;
    }   
    else {
        vector <int> ans(2 * n - 1), l, r;
        for (int i = 1; i < x; ++i)
            l.app(i);
        for (int i = x + 1; i <= 2 * n - 1; ++i)
            r.app(i);
        ans[n - 1] = x;

        if (l.size() >= 2) {
            ans[n - 2] = l.back(); l.pop_back();
            ans[n] = r.back(); r.pop_back();
            ans[n + 1] = l.back(); l.pop_back();
        }   
        else if (r.size() >= 2) {
            ans[n - 2] = l.back(); l.pop_back();
            ans[n - 3] = r.back(); r.pop_back();
            ans[n] = r.back(); r.pop_back();
        }   

        for (int &e : ans) {
            if (e == 0) {
                if (l.size()) {
                    e = l.back();
                    l.pop_back();
                }   
                else {
                    e = r.back();
                    r.pop_back();
                }   
            }   
        }   
        cout << "Yes" << endl;
        for (int e : ans)
            cout << e << ' ';
        cout << endl;
    }   
}