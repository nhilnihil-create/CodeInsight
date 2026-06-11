#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    string r1,r2,r3,r4;
    for(int i = 0; i < ty-sy; i++){
        r1.push_back('U');
        r2.push_back('D');
    }
    for(int i = 0; i < tx-sx; i++){
        r1.push_back('R');
        r2.push_back('L');
    }
    r3.push_back('L');
    r4.push_back('R');
    for(int i = 0; i < ty-sy+1; i++){
        r3.push_back('U');
        r4.push_back('D');
    }
    for(int i = 0; i < tx-sx+1; i++){
        r3.push_back('R');
        r4.push_back('L');
    }
    r3.push_back('D');
    r4.push_back('U');
    string ans;
    ans = r1+r2+r3+r4;
    cout << ans << endl;
}