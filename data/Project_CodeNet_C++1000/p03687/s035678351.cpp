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

    string s;
    cin >> s;
    int ans = s.size();
    for (char c = 'a'; c <= 'z'; ++c) {
        vector <int> pos;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == c)
                pos.app(i);
        }   
        if (pos.empty())
            continue;
        int nn = 0;
        nn = max(nn, pos[0]);
        nn = max(nn, (int)s.size() - pos.back() - 1);
        for (int i = 0; i + 1 < pos.size(); ++i)    
            nn = max(nn, (pos[i + 1] - pos[i] - 1));
        ans = min(ans, nn);
    }
    cout << ans << endl;

}