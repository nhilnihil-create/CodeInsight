#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 998244353;


int main() {
    string s;
    cin >> s;
    int eidx = s.size();
    vector<string> words{"dream", "dreamer", "erase", "eraser"}; 
    while (eidx > 0) {
        bool check = true; 
        for (const auto& c : words) {
            int ws = c.size();
            if (check && eidx >= ws && s.compare(eidx-ws, ws, c) == 0) {
                eidx -= ws;
                check = false;    
            }  
        }
        if (check) break;
    } 
    string ret = (eidx == 0 ? "YES" : "NO");
    cout << ret << endl;
    return 0;
}