#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

string s;
void solve(){
    cin >> s;
    int n = (int)s.size();
    if(n == 2) {
        if(s[0] == s[1])
            cout << 1 << " " << 2 << "\n";
        else
            cout << -1 << " " << -1 << "\n";
        return;
    }
    auto ok = [&](int i) {
        return (s[i] == s[i+1] || s[i] == s[i+2] || s[i+1] == s[i+2]);
    };
    for(int i=0;i+2<n;++i) {
        if(ok(i)) {
            cout << i+1 << " " << i+2+1 << "\n";
            return;
        }
    }
    cout << "-1 -1\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t =1;
    while(t--)
        solve();
    return 0;
}

