#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    int max_count = 0;
    int max_count_index = -1;
    for (int i = 1; i <= N; i++) {
        int tmp = i;
        int count = 0;
        while (tmp > 0) {
            if (tmp % 2 == 0) {
                count++;
                tmp /= 2;
            } else {
                break;
            }
        }
        if (count >= max_count) {
            max_count = count;
            max_count_index = i;
        }
    }

    cout << max_count_index << endl;
}