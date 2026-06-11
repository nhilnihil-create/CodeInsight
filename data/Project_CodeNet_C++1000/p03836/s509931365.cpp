#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <climits>
using namespace std;
#define rep(i,l,r) for(int (i)=(int)(l);(i)<(int)(r);(i)++)
#define ll long long
#define ve vector
#define umap unordered_map
#define iter iterator


int main() {
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    int x = tx-sx, y = ty-sy;
    rep(i,0,y) cout<<'U';
    rep(i,0,x) cout<<'R';
    cout<<'U';
    rep(i,0,x+1) cout<<'L';
    rep(i,0,y+1) cout<<'D';
    rep(i,0,x+1) cout<<'R';
    rep(i,0,y) cout<<'U';
    cout<<'R';
    rep(i,0,y+1) cout<<'D';
    rep(i,0,x+1) cout<<'L';
    cout<<'U'<<endl;

    return 0;
}