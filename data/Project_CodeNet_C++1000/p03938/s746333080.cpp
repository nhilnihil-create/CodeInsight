#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
        p[i]--;
    }

    int M = 50000;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        a[i] = M * (i + 1);
        b[i] = M * (N - i - 1) + 1;
    }

    int min = 1;
    for (int i = 0; i < N; i++) {
        if (a[p[i]] + b[p[i]] < min) {
            b[p[i]] += min - (a[p[i]] + b[p[i]]);
        }
        min = a[p[i]] + b[p[i]] + 1;
    }

    for (int i = 0; i < N - 1; i++) {
        cout << a[i] << " ";
    }
    cout << a[N - 1] << endl;
    for (int i = 0; i < N - 1; i++) {
        cout << b[i] << " ";
    }
    cout << b[N - 1] << endl;
}
