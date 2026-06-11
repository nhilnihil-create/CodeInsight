#include <bits/stdc++.h>
using namespace std;
int h, w, n;
int main() {
    cin >> h >> w;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; ++i) cin >> a.at(i);

    vector<vector<int>> mas(h, vector<int>(w, 0));
    int idx = 0;
    for(int i = 0; i < h; ++i) {
        if(i % 2 == 0) {
            for(int j = 0; j < w; ++j) {
                if(a.at(idx) > 1) {
                    mas.at(i).at(j) = idx+1;
                    a.at(idx)--;
                }else {
                    mas.at(i).at(j) = idx+1;
                    idx++;
                }
            }
        }else {
            for(int j = w-1; j >= 0; --j) {
                if(a.at(idx) > 1) {
                    mas.at(i).at(j) = idx+1;
                    a.at(idx)--;
                }else {
                    mas.at(i).at(j) = idx+1;
                    idx++;
                }
            }
        }
    }

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            cout << mas.at(i).at(j) << " ";
        }
        cout << endl;
    }
}