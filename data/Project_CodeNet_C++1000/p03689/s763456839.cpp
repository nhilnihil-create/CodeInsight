#include <bits/stdc++.h>
#define rep(i, n) for (int i = 1; i <= (n); i++)
using namespace std;

int main(){
    int H, W, h ,w; cin >> H >> W >> h >> w;
    if( !(H%h) && !(W%w) ) cout << "No" << endl;
    else{
        cout << "Yes" << endl;
        rep(i,H) rep(j,W){
            if( !(i%h) && !(j%w) ) cout << (h*w-1)*(-1000)-1;
            else cout << 1000;
            if(j == W) cout << endl;
            else cout << " ";
        }
    }
}