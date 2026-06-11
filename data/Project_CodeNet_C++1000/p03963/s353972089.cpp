#include <bits/stdc++.h>
using namespace std;


int main() {
    int N, K;
    cin >> N >> K;

    int num = K;
    for (int i = 0; i < N - 1; i++) num *= K - 1;
    cout << num << endl;
}