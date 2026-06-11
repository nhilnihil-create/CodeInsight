#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
signed main(){
    string s;cin >> s;
    int n = s.size();
    char now = s[0];
    int cnt = 0;
    rep(i,n-1){
        if(s[i+1] != now){
            now = s[i+1];
            cnt++;
        }

    }
    cout << cnt << endl;
    return 0;
}