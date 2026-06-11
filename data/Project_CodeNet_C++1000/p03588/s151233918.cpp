#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int X = 0;
    int Y = 1e9;
    for(int i = 0; i < N; i++) {
        int A,B;
        cin >> A >> B;
        X = max(X,A);
        Y = min(Y,B);
    }
    cout << X+Y << endl;
}