#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    string temp;
    rep(i,n) {
        if(s.substr(i, n) == t.substr(0, n-i)){
            temp = s.substr(0, i) + t;
            int ans = temp.size();
            cout << ans << endl;
            return 0;
        }
    }
    int ans = s.size() + t.size();
    cout << ans << endl;
    return 0;
}