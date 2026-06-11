#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int cnt[100002] = {};
    int a;
    while (cin >> a) {
        cnt[a-1]++;
        cnt[a]++;
        cnt[a+1]++;
    }
    int maxCnt = 0;
    for (int i=1; i<100001; i++) {
        maxCnt = max(maxCnt, cnt[i]);
    }
    cout << maxCnt << endl;
}