#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int result = K;

    for (int i = 2; i <= N; i++)
        result *= K - 1;
    
    cout << result << endl;
}