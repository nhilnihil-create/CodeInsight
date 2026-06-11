#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    int h,w;
    cin >> h >> w;

    char C[h][w];
    rep(i,h){
        rep(j,w){
            cin >> C[i][j];
        }
    }

    for(int i=0;i<2*h;i++){
        rep(j,w){
            cout << C[i/2][j];
        }
        cout << endl;
    }

    return 0;
}