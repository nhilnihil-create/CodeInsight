#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int w, h, num;
    int tmpW, tmpH, que;
    int cnt = 0;
    cin >> w >> h >> num;

    vector<vector<int>> data(w, vector<int>(h));

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) data.at(i).at(j) = 0;
    }

    for (int i = 0; i < num; i++) {
        //
        cin >> tmpW >> tmpH >> que;
        if (que == 1) {
            for (int i = 0; i < tmpW; i++) {
                //
                for (int j = 0; j < h; j++) {
                    //
                    data.at(i).at(j) = 1;
                }
            }
        } else if (que == 2) {
            for (int i = tmpW; i < w; i++) {
                //
                for (int j = 0; j < h; j++) {
                    //
                    data.at(i).at(j) = 1;
                }
            }
        } else if (que == 3) {
            for (int i = 0; i < w; i++) {
                //
                for (int j = 0; j < tmpH; j++) {
                    //
                    data.at(i).at(j) = 1;
                }
            }
        } else if (que == 4) {
            for (int i = 0; i < w; i++) {
                //
                for (int j = tmpH; j < h; j++) {
                    //
                    data.at(i).at(j) = 1;
                }
            }
        }
    }

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (data.at(i).at(j) == 0) cnt++;
        }
    }

    cout << cnt;
    //
}