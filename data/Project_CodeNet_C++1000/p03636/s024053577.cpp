// AtCoder template
// sabaより胡蝶しのぶさんの方が可愛いのではないか？
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s; cin >> s;
    string ans = s[0] + to_string(s.size()-2) + s[s.size()-1];
    cout << ans << endl;
}