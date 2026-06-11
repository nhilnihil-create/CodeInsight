#include<bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    long long a[N], b[N];

    for (int i = 0; i < N; i++)
    {
        cin >> a[i] >> b[i];
    }

    long long ans = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if((a[i] + ans) % b[i] != 0 ) ans += b[i] - ((a[i] + ans) % b[i]);
    }

    cout << ans << endl;
}