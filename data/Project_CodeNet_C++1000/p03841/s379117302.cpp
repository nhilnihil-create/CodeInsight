#include <bits/stdc++.h>
using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// cout << fixed << setprecision(20);

int N;
int x[550], a[330000];
signed main() {
    cin >> N;
    for (int i = 1; i <= N; i++)cin >> x[i];
    for (int i = 1; i <= N; i++) {
        if (a[x[i]] != 0) {cout << "No" << endl; return 0;}
        a[x[i]] = i;
    }
    queue<int> l, r;
    for (int i = 1; i <= N * N; i++) {
        if (a[i] != 0) {
            for (int j = 0; j < a[i] - 1; j++)l.push(a[i]);
        }
    }
    for (int i = N * N; i >= 1; i--) {
        if (a[i] != 0) {
            for (int j = 0; j < N - a[i]; j++)r.push(a[i]);
        }
    }

    for (int i = 1; i <= N * N; i++) {
        if (l.empty())break;
        if (x[l.front()] < i) {cout << "No" << endl; return 0;}
        if (a[i] != 0)continue;
        a[i] = l.front(), l.pop();
    }
    for (int i = N * N; i >= 1; i--) {
        if (r.empty())break;
        if (x[r.front()] > i) {cout << "No" << endl; return 0;}
        if (a[i] != 0)continue;
        a[i] = r.front(), r.pop();
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= N * N; i++)cout << a[i] << " ";
    cout << endl;
}
