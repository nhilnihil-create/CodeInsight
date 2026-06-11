#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<int> A(N,0);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
        sum += A.at(i);
    }
    int M;
    cin >> M;
    for(int i = 0; i < M; i++) {
        int P, X;
        cin >> P >> X;

        cout << sum - A.at(P - 1) + X << endl;
    }



    return 0;
}