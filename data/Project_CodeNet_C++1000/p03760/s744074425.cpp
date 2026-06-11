#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    string s, t;
    cin >> s >> t;
    int n = max(s.size(), t.size());
    rep(i,n){
        if(i<s.size()) cout << s[i];
        if(i<t.size()) cout << t[i];
    }
    cout << endl;
    return 0;
}