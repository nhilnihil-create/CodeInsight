#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    long long H, W, N;
    cin >> H >> W >> N;
    int a[N], b[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<pair<int, int>> rectangle;
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < 3; ++k) {
            for (int l = 0; l < 3; ++l) {
                if (1 <= a[i] - k && a[i] - k <= H - 2 && 1 <= b[i] - l && b[i] - l <= W - 2) {
                    pair<int, int> push;
                    push.first = a[i] - k, push.second = b[i] - l;
                    rectangle.push_back(push);
                }
            }
        }
    }

    sort(rectangle.begin(), rectangle.end());
//    for (int i = 0; i < rectangle.size(); ++i) {
//        cout << rectangle[i].first << " " << rectangle[i].second << endl;
//    }

    long long sum[10] = {};
    long long cnt = 1;
    for (int i = 0; i < rectangle.size(); ++i) {
        if (rectangle[i] == rectangle[i + 1]) {
//            cout << "same" << endl;
            cnt++;
        } else {
//            cout << "deff" << endl;
            sum[cnt]++;
            cnt = 1;
        }
    }

    long long sumzero = (H - 2) * (W - 2);
    for (int i = 1; i < 10; ++i) {
        sumzero -= sum[i];
    }

    cout << sumzero << endl;
    for (int i = 1; i < 10; ++i) {
        cout << sum[i] << endl;
    }
    return 0;
}