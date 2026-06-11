#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int N, P;
    cin >> N >> P;
    vector<int> A(N + 10);

    for(int i = 0; i < N; i++)cin >> A[i];

    int even = 1;
    for(int i = 0; i < N; i++)if(A[i] % 2 == 0)even *= 2;

    int odd = 0, odd_N = 0, tmp = 1;
    for(int i = 0; i < N; i++)if(A[i] % 2)odd_N++;
    for(int i = 0; i <= odd_N; i++)
    {
        if(i % 2 == P)odd += tmp;
        tmp *= odd_N - i;
        tmp /= i + 1;
    }

    cout << odd * even << endl;

    return 0;
}
