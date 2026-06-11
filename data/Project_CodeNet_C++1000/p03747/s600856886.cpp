#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_N = 1e5 + 5;
int n, L, T;
int X[MAX_N];
int W[MAX_N];
int fin[MAX_N];
int shift;

void find() {
    for (int i = 0; i < n; i++) {
        if (W[i] == 1)
            shift = (shift + (X[i] + T) / L) % n;
        else
            shift = (((shift + (X[i] - T - L + 1) / L) % n) + n) % n;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> L >> T;
    for (int i = 0; i < n; i++)
        cin >> X[i] >> W[i];

    for (int i = 0; i < n; i++) {
        if (W[i] == 1)
            fin[i] = (X[i] + T) % L;
        else
            fin[i] = ((X[i] - T) % L + L) % L;
    }

    sort(fin, fin + n);
    find();
    for (int i = shift; i < n; i++)
        cout << fin[i] << " ";
    for (int i = 0; i < shift; i ++)
        cout << fin[i] << " ";
    return 0;
}