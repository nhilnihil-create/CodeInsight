#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
    #include "/home/v-o_o-v/deb.h"
    #define deb(x...)cerr << "[" << #x << "] = [";_print(x);
#else
    #define deb(x...)
#endif

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int cnt[55];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    set<char> st;
    for(auto ch: s)st.insert(ch);
    if(st.size() == s.size())puts("yes");
    else puts("no");
    return 0;
}
// Write Here
