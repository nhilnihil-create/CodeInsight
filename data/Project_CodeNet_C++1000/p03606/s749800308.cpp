#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int l[2][1000];
    int Sum = 0;
    for(int i = 0; i < N; ++i) {
        cin >> l[0][i] >> l[1][i];
        Sum += l[1][i] - l[0][i] + 1;
    }
    cout << Sum << endl;
}