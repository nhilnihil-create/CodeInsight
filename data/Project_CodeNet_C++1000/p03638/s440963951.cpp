#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);
int main(){
    int h, w, n, tmp;
    sc(h) sc(w) sc(n)
    int a[n];
    for (int i = 0; i < n; i++) sc(a[i])
    int ans[h][w];
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            ans[i][j] = -1;
        }
    }
    int row = 0, col = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < a[i]; j++){
            if (row % 2 == 0 && col == w - 1){
                ans[row][col] = i + 1;
                row += 1;
            }else if (row % 2 == 1 && col == 0){
                ans[row][col] = i + 1;
                row += 1;
            }else {
                ans[row][col] = i + 1;
                if (row % 2 == 0) col += 1;
                else col -= 1;
            }
        }
    }
    for (int i = 0; i < h; i++){
        cout << ans[i][0];
        for (int j = 1; j < w; j++){
            cout << " " << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}