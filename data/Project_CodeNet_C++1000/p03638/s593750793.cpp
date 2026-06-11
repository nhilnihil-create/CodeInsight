#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int64_t H,W;
    int64_t N;
    int64_t x=0,y=0;
    int64_t a;
    cin >> H >> W;
    cin >> N;

    vector<vector<int64_t>> hw(H,vector<int64_t>(W,0));
    for(int i=0;i<N;i++) {
        cin >> a;
        while(a){
            if(y % 2) {
                while(a){
                    hw[y][x--] = i+1;
                    a--;
                    if(x < 0){
                        x++;
                        y++;
                        break;
                    }
                }
            } else {
                while(a){
                    hw[y][x++] = i+1;
                    a--;
                    if(x == W){
                        x--;
                        y++;
                        break;
                    }
                }
            }
        }
    }

    for(int i=0;i<H;i++) {
        cout << hw[i][0];
        for(int j=1;j<W;j++) {
            cout << " " << hw[i][j];
        }

        cout << "\n";
    }
    return 0;
}
