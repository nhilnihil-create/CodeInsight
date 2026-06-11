#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];
    rep(i, 0, h){
        if(i == 0){
            rep(k, 0, w+2) cout << '#';
            cout << endl;
        }
        cout << '#';
        rep(j, 0, w){
            cout << s[i][j];
        }
        cout << '#' << endl;
        if(i == h-1){
            rep(k, 0, w+2) cout << '#';
            cout << endl;
        }
    }
    return 0;
}
