#include <bits/stdc++.h>

using namespace std;

const int maxn = 100003;

int number[maxn];
bool redball[maxn];

int main() {
    int N, M, x, y;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        number[i] = 1;
        redball[i] = 0;
    }
    redball[1] = 1;
    for (int i = 1; i <= M; i++) {
        cin >> x >> y;
        if (redball[x]) {
            redball[y] = 1;
        }
        number[x] -= 1;
        number[y] += 1;
        if (number[x] == 0) {
            redball[x] = 0;
        }
    }
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (redball[i] == true) {
            sum += 1;
        }
    }
    cout << sum << endl;
}