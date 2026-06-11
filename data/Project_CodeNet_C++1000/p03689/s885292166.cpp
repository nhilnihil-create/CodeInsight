#include <iostream>
#include <cstring>
using namespace std;
const int M = 5e2 + 10;
int mmp[M][M] , ans[M][M];
int main() {
    int H , W , h , w;
    cin >> H >> W >> h >> w;
    for(int i = 1 ; i <= H ; i++) {
        for(int j = 1 ; j <= W ; j++) {
            ans[i][j] = 1;
        }
    }
    for(int i = 1 ; i <= H ; i++) {
        if(i % h == 0) {
            for(int j = 1 ; j <= W ; j++) {
                if(j % w == 0) {
                    ans[i][j] = -(h * w);
                }
            }
        }
    }
    int count = 0 , cnt = 0;
    for(int i = 1 ; i <= H ; i++) {
        for(int j = 1 ; j <= W ; j++) {
            if(ans[i][j] > 0) count++;
            cnt += ans[i][j];
        }
    }
    if(cnt+H*W-count<=0 && cnt <= 0) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        int sum = 0;
        for(int i = 1 ; i <= H ; i++) {
            for(int j = 1 ; j <= W ; j++) {
                sum += ans[i][j];
            }
        }
        int num1 = count , num2 = H * W - count;
        int dif = num1 - num2 * (h * w - 1);
        if(sum <= 0) {
            int gg = -sum;
            int ad = gg / dif + 1;
            for(int i = 1 ; i <= H ; i++) {
                for(int j = 1 ; j <= W ; j++) {
                    if(ans[i][j] > 0) ans[i][j] += ad;
                    else ans[i][j] -= ad * (h * w - 1);
                }
            }
        }
        for(int i = 1 ; i <= H ; i++) {
            for(int j = 1 ; j <= W ; j++) {
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}