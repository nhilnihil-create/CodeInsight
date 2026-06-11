#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main() {
    int N, M;
    cin >> N;

    vector<int> v(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> v.at(i);
        sum += v.at(i);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int P, X;
        cin >> P >> X;

        int n = sum - (v.at(P - 1) - X);
        cout << n << endl;
    }
}