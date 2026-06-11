//きれいな解説コード
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;

int main(){
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    const int dx = tx-sx,dy=ty-sy;

    //Path1
    cout << string(dy,'U') << string(dx,'R');
    //Path2
    cout << string(dy,'D') << string(dx,'L');
    //Path3
    cout << 'L' << string(dy+1,'U') << string(dx+1,'R') << 'D';
    //Path4
    cout << 'R' << string(dy+1,'D') << string(dx+1,'L') << 'U';

    //Endline
    cout << endl;
	return 0;
}