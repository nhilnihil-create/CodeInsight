#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;



int main(){
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    int y = ty - sy, x = tx - sx;
    string ans = "";
    for(int i = 0; i < y; i++) ans += "U";
    for(int i = 0; i < x; i++) ans += "R";
    for(int i = 0; i < y; i++) ans += "D";
    for(int i = 0; i < x; i++) ans += "L";

    ans += "L";
    for(int i = 0; i < y+1; i++) ans += "U";
    for(int i = 0; i < x+1; i++) ans += "R";
    ans += "D";
    ans += "R";
    for(int i = 0; i < y+1; i++) ans += "D";
    for(int i = 0; i < x+1; i++) ans += "L";
    ans += "U";
    cout << ans << endl;

}
