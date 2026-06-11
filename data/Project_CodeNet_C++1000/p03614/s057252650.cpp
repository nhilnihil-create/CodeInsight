#include <iostream>
using namespace std;

int main() {
    int n, result = 0;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    if (p[0] == 1) {
        swap(p[0], p[1]);
        result++;
    }
    for (int i = 1; i < n; i++) {
        if (p[i] == i + 1) {
            if (i + 1 < n && p[i + 1] == i + 2) {
                swap(p[i], p[i + 1]);
            }
            result++;
        }
    }
    cout << result;
    return 0;
}
