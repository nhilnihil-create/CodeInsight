#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H, W, N; cin >> H >> W >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<vector<int>> ans(H, vector<int>(W));
    int pos = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int jt;
            if(i%2==1) jt = W-1-j;
            else jt = j;
            if(a[pos]!=0){
                a[pos]--;
            } else {
                pos++;
                a[pos]--;
            }
            ans[i][jt] = pos+1;
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << ans[i][j];
            if(j!=W-1) cout << " ";
            else cout << endl;
        }
    }
}