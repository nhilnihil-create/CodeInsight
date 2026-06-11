#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    int p = 0;
    int cnt = 0;
    rep(i,s.size()) {
        if(s[i]=='S') p++;
        else{
            if(p){
                cnt++;
                p--;
            }
        }
    }
    int ans = s.size()-cnt*2;
    cout << ans << endl;
    return 0;
}