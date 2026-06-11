#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    int64_t sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i);
        sum += A.at(i);
    }
    sort(A.rbegin(), A.rend());

    int res = 1;
    int Ap = A.at(0);
    for (int i = 1; i < N; i++)
    {
        sum -= Ap;
        if (Ap > sum * 2)
        {
            break;
        }
        res++;
        Ap = A.at(i);
    }
    cout << res << endl;
}