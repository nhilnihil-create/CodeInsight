#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    int K = 0;
    cin >> K;

    int ans = 0;
    int temp;
    for (size_t i = 0; i < N; i++)
    {
        cin >> temp;
        ans += min(abs(K-temp),abs(temp));
    }
    cout << ans*2 << endl;
    

    return 0;
}