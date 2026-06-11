#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef unsigned long long ll;

int main(){
    // read in integers
    string s;
    cin >> s;

    string ans = "";

    REP(i, s.size()){
        if (s[i] == 'B') {
            if (ans.size() != 0)ans.pop_back();
        }
        else ans += s[i];
    }

    cout << ans << endl;
}