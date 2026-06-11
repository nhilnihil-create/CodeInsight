#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(void) {
    io;
    int n;
    string s;
    cin >> n >> s;
    int x = 0;
    int res = 0;
    rep(i,n) {
        if (s[i] == 'D') {
            x--;
        } else {
            x++;
        }
        if (res < x) res = x;
    }
    cout << res << "\n";
    return 0;
}

