#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct box {
    bool red;
    int num;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<box> boxes(N);
    for (int i = 0; i < N; i++) {
        boxes[i].red = false;
        boxes[i].num = 1;
    }
    boxes[0].red = true;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        if (boxes[x - 1].red && boxes[x - 1].num == 1) {
            boxes[x - 1].red = false;
            boxes[x - 1].num--;
            boxes[y - 1].red = true;
            boxes[y - 1].num++;
        } else if (boxes[x - 1].red) {
            boxes[x - 1].num--;
            boxes[y - 1].red = true;
            boxes[y - 1].num++;
        } else {
            boxes[x - 1].num--;
            boxes[y - 1].num++;
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (boxes[i].red) {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}
