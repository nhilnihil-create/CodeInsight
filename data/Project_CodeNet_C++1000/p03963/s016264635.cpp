#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N, K;

    cin >> N >> K;

    long long int ans = K;

    for(int i = 1; i < N; ++i)
    {   
        ans *= K-1;
    }

    cout << ans << endl;

    return 0;
}

