#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n; cin >> n;
    const int p = 8;
    vector<bool> num(p, false);
    int freeCnt = 0;
    for (int i = 0; i < n; i++) {
        int rate; cin >> rate;
        for (int j = 0; j <= p; j++) {
            if (400 * j <= rate && rate <= 400 * (j + 1) - 1 && j < p ) {
                num[j] = true;
            }
            else if (400 * j <= rate && j == p) {
                freeCnt++;
            }
        }
    }


    int cnt = 0;
    for (int i = 0; i < p; i++) {
        if (num[i]) cnt++;
    }
    
    int minCnt;
    if (cnt == 0) minCnt = 1;
    else minCnt = cnt;

    int maxCnt = cnt + freeCnt;

    cout << minCnt << " " << maxCnt << endl;
    return 0;
}