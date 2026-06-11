#include <bits/stdc++.h>
using namespace std;
const int MAX=2020;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H,W,d; cin >> H >> W >> d;
    vector<vector<char>> ans(H,vector<char>(W));
    if (d&1){
        for (int i=0;i<H;++i)
            for (int j=0;j<W;++j)
                ans[i][j]=((i+j)&1?'R':'Y');
    } else {
        vector<vector<char>> C={{'R','Y'},{'G','B'}};
        vector<vector<char>> rot(MAX,vector<char>(MAX));
        for (int i=0;i<MAX;i+=d){
            for (int j=0;j<MAX;j+=d){
                rot[i][j]=C[(i/d)&1][(j/d)&1];
                for (int k=0;k<d/2&&i+2*k<MAX;++k){
                    for (int l=0;l<d/2&&j+2*l<MAX;++l){
                        rot[i+2*k][j+2*l]=rot[i][j];
                    }
                }
            }
        }
        for (int i=0;i<H;++i){
            for (int j=0;j<W;++j){
                ans[i][j]=rot[i+j+((i+j)&1)][(i-j)+MAX/2+((i+j)&1)];
            }
        }
    }
    for (int i=0;i<H;++i)
        for (int j=0;j<W;++j)
            cout << ans[i][j] << (j+1==W?"\n":"");
}