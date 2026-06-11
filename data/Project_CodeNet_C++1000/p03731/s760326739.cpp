#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>
#include <bitset>
#include <queue>

using namespace std;

void solve() {
    int n, t;
    cin >> n >> t;
    int oyutime = 0;
    int endtime = 0;
    for(int i = 0; i < n; i++) {
        int time;
        cin >> time;
        // お湯が出ていないときに押したとき
        if(endtime < time) {
            oyutime += t;
            endtime = time+t;

        // お湯が出ているときに押したとき
        } else {
            oyutime += (time+t - endtime);
            endtime = time+t;
        }
    }
    cout << oyutime;
}

int main() {
    solve();
    return 0;
}