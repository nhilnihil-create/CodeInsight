#include <iostream>
#include <vector>

using namespace std;

const int dh[4]={0, 1, 0, -1};
const int dw[4]={1, 0, -1, 0};

int main() {
    int H, W;
    cin >> H >> W;
    
    int N;
    cin >> N;
    
    int curh=0, curw=0;
    int curd=0;
    vector<vector<int> > ans(H, vector<int>(W, -1));
    for(int n=0; n<N; n++) {
        int a;
        cin >> a;
        for(int j=0; j<a; j++) {
            ans[curh][curw] = n+1;
            int nxh=curh+dh[curd];
            int nxw=curw+dw[curd];

            if(nxh<0 || nxh>=H || nxw<0 || nxw>=W) {
                curd++;
            } else if(ans[nxh][nxw]!=-1) {
                curd++;
            }
            curd %= 4;
            curh += dh[curd];
            curw += dw[curd];
        }
    }
    
    for(int h=0; h<H; h++) {
        for(int w=0; w<W; w++) {
            cout << ans[h][w] << " ";
        }
        cout << endl;
    }


    return 0;
    
}