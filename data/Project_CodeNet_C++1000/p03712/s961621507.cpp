#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];
    rep(i, 0, w+2) cout << '#';
    cout << endl;
    rep(i, 0, h) cout << '#' << s[i] << '#' << endl;
    rep(i, 0, w+2) cout << '#';
    cout << endl;
    return 0;
}