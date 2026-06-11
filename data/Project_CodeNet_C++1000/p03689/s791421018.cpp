#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int H, W, h, w;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> H >> W >> h >> w;
    if(H % h == 0 && W % w == 0) finish("No");
    cout << "Yes" << endl;
    int c = h;
    if(H % h == 0) c = w;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            if((c == h && i % h == 0) || (c == w && h != w && j % w == 0)) cout << 1000 * (c - 1) - 1 << " ";
            else cout << -1000 << " ";
        }
        cout << endl;
    }
}
