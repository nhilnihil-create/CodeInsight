#include <bits/stdc++.h>
using namespace std;

int main()
{

        int H, W;
        cin >> H >> W;
        int N;
        cin >> N;
        int a[N];
        for (int i = 0; i < N; ++i) {
                cin >> a[i];
        }

        int t = 0;
        int res[H][W];
        for (int i = 0; i < H; ++i) {

                if (i % 2 == 0) {

                        for (int j = 0; j < W; ++j) {
                                if (a[t] == 0) {
                                        t++;
                                }
                                res[i][j] = t + 1;
                                a[t]--;
                        }

                }
                else {

                        for (int j = W - 1; j > -1; --j) {

                                if (a[t] == 0) {
                                        t++;
                                }
                                res[i][j] = t + 1;
                                a[t]--;

                        }
                }

                for (int j = 0; j < W; ++j) {

                        cout << res[i][j] << " ";

                }
                cout << endl;

        }






}
