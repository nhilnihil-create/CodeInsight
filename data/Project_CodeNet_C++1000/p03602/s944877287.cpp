#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    long long result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool valid = true;
            for (int k = 0; k < n; k++) {
                if (a[i][k] + a[k][j] < a[i][j]) {
                    result = -1;
                    goto end;
                }
                if (k != i && k != j && a[i][k] + a[k][j] == a[i][j]) {
                    valid = false;
                }
            }
            if (valid) {
                result += a[i][j];
            }
        }
    }
    end:
    cout << result;
    return 0;
}
