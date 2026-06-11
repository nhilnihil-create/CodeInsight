// Snake Toy
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    int L[60];
    int su = 0;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> L[i];
    sort(L, L+N, greater<int>());
    for (int k = 0; k < K; ++k) su += L[k];
    cout << su << endl;
}