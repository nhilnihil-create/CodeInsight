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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    s.pop_back();
    while(true){
        if(s.size() % 2)s.pop_back();
        if(s.substr(0, s.size() / 2) == s.substr(s.size() / 2))break;
        s.pop_back();
    }
    cout << s.size() << '\n';
    return 0;
}
// Write Here
