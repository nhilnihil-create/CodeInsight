#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    rep(i,ty-sy) cout << "U";
    rep(i,tx-sx) cout << "R";
    rep(i,ty-sy) cout << "D";
    rep(i,tx-sx) cout << "L";
    cout << "L";
    rep(i,ty-sy+1) cout << "U";
    rep(i,tx-sx+1) cout << "R";
    cout << "D";
    cout << "R";
    rep(i,ty-sy+1) cout << "D";
    rep(i,tx-sx+1) cout << "L";
    cout << "U";
    cout << endl;
    return 0;
}