#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
    int n, l; cin >> n >> l;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    sort(s.begin(), s.end());

    string ans="";
    rep(i, n){
        ans.append(s[i]);
    }
    cout << ans << endl;
    return 0;
}