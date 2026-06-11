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
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    vector < vector <char> > a = { {'N', 'S'}, {'W', 'E'} };
    vector <vector <bool> > h(2);
    for (int i = 0; i < 2; ++i)
        h[i].resize(2);
    string s;
    cin >> s;
    for (char c : s) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                h[i][j] = h[i][j] | (c == a[i][j]);
            }   
        }   
    }   
    for (int i = 0; i < 2; ++i) {
        if (h[i][0] ^ h[i][1]) {
            cout << "No" << endl;
            exit(0);
        }   
    }
    cout << "Yes" << endl;
    
}