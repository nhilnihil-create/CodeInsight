#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    string s; cin >> s;
    int n = s.size();
    int scnt = 0;
    int ans = 0;
    rep(i, n){
        if(s[i] == 'S'){
            scnt++;
        } else {
            if(scnt == 0){
                ans++;
            } else {
                scnt--;
            }
        }
        if(i == n-1){
            ans += scnt;
        }
    }

    cout << ans << endl;

    return 0;
}