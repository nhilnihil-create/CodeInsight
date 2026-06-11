#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    int u,r;
    u=ty-sy;
    r=tx-sx;
    rep(i,u)cout<<'U';
    rep(i,r)cout<<'R';
    rep(i,u)cout<<'D';
    rep(i,r+1)cout<<'L';
    rep(i,u+1)cout<<'U';
    rep(i,r+1)cout<<'R';
    cout<<'D'<<'R';
    rep(i,u+1)cout<<'D';
    rep(i,r+1)cout<<'L';
    cout<<'U';
	return 0;
}
