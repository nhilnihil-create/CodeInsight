#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const long double PI = (acos(-1));
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
int main(){
    int now = 0;
    bool check;
    string s, tmp; cin >> s;
    reverse(s.begin(), s.end());
    vector<string> v(4);
    v[0] = "dream", v[1] = "dreamer", v[2] = "erase", v[3] = "eraser";
    rep(i, 0, 4) reverse(v[i].begin(), v[i].end());
    while(1){
        check = false;
        rep(i, 0, 4){
            if (i == 0 || i == 2) tmp = s.substr(now, 5);
            else if (i == 1) tmp = s.substr(now, 7);
            else tmp = s.substr(now, 6);
            if (tmp == v[i]) check = true, now += tmp.size();
            if (check) break;
        }
        if (!check) break;
        if (now == s.size()) break;
    }
    if (check) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}