#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    s.erase(n-1);
    rep(i,n-1) {
        if((int)s.size()%2) {s.erase(s.size()-1); continue;}
        string temp = s.substr(s.size()/2, s.size());
        if(s.substr(0,s.size()/2)==temp) ans = max(ans, (int)s.size());
        s.erase(s.size()-1);
    }
    cout << ans << endl;
    return 0;
}