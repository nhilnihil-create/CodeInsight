#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}

int res[100][100];

int main() {
    int H, W; cin >> H >> W;
    int N; cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
 
    int k = 0;
    for (int i = 0; i < H; i++) {
        if (i % 2 == 0) 
        for (int j = 0; j < W; j++) {
            res[i][j] = k+1;
            a[k]--;
            if (a[k] == 0) k++;
        }
        else 
        for (int j = W-1; j >= 0; j--) {
            res[i][j] = k+1;
            a[k]--;
            if (a[k] == 0) k++;
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << res[i][j] << " ";
        } cout << endl;
    }
}
