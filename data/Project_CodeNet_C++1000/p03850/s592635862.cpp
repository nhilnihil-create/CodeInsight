#include <bits/stdc++.h>
using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int N;
int A[110000];
char op[110000];

signed main() {
    cin >> N;
    cin >> A[0];
    for (int i = 1; i < N; i++)cin >> op[i] >> A[i];
    op[N] = '-'; A[N] = 0;

    int sum = A[0], total_minus = 0, cur_minus = 0, min_minus = LLONG_MAX;
    for (int i = 1; i <= N; i++) {
        if (op[i] == '+') {
            if (total_minus > 0)cur_minus += A[i];
        } else {
            if (total_minus > 0)min_minus = min(min_minus, total_minus + cur_minus);
            total_minus += A[i];
            cur_minus = 0;
        }
        sum += A[i];
    }
    if (min_minus == LLONG_MAX)min_minus = 0;
    cout << sum - 2 * min_minus;

}
