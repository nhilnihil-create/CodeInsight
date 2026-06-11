#include <bits/stdc++.h>
using ll = long long int;
using namespace std;

int main()
{
    int N, cnt = 0;
    cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (A[i] & 1)
        {
            cnt++;
        }
    }
    if (cnt & 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    return 0;
}