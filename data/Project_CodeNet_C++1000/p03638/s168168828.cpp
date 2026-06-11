#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
#define ll long long
#define rep(i, s, n) for(int i = s; i < n; i++)

int main() {
    int h, w;
    cin >> h >> w;
    int n;
    cin >> n;
    int hw = h*w;
    vector<vector<int>> c(h, vector<int>(w, 0));
    vector<int> a(n);
    int cx = 0, cy = 0;
    int flag = 0;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) {
        int c_number = i+1;
        //cout << i+1 << " " << a[i] << endl;
        rep(j, 0, a[i]) {
            c[cx][cy] = c_number;
            if(cx+1 < h && flag == 0) {
                cx++;
            }
            else if(cx+1 >= h && flag == 0) {
                cy++;
                flag = 1;
            }
            else if(cx-1 >= 0 && flag == 1) {
                cx--;
            }
            else if(cx-1 < 0 && flag == 1) {
                flag = 0;
                cy++;
            }
        }
    }

    rep(i, 0, h) {
        rep(j, 0, w) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}