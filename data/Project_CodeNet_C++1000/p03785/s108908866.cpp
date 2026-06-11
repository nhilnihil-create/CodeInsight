#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    long C, K;
    cin >> C >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int c = 0;
    // int capa = 1;
    int t;
    // string state = "DEP";
    for (int i = 0; i < N;) {
        c++;
        t = i;
        while (i < N && A[i] - A[t] <=K && i - t < C)
            i++;
    }
    cout << c << endl;
}