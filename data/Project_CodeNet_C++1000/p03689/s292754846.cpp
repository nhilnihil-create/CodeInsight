#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
//#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int mod = 1e9 + 7;
const int N = 2005;
const int K = 50;
set < int > g1[N], g2[N];
int a[N][N];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    if (H % h == 0 && W % w == 0){
        cout << "No";
        return 0;
    }
    cout << "Yes" << endl;
    if (H % h != 0){
        int r = H % h;
        int x = 1e9;
        x /= h;
        int s1 = x * w * r;
        int y = -(s1 / (w * h - w * r) + 1);
        for (int i = 0; i < H; i++){
            for (int j = 0; j < W; j++){
                if (i % h < r){
                    a[i][j] = x;
                } else{
                    a[i][j] = y;
                }
            }
        }
    } else{
        int r = W % w;
        int x = 1e9;
        x /= w;
        int s1 = x * h * r;
        int y = -(s1 / (w * h - h * r) + 1);
        for (int i = 0; i < H; i++){
            for (int j = 0; j < W; j++){
                if (j % w < r){
                    a[i][j] = x;
                } else{
                    a[i][j] = y;
                }
            }
        }
    }
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
