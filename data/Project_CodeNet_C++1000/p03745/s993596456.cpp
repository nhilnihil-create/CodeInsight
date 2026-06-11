#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    char op = '.';
    int res = 0;
    rep(i, N)
    {
        if (i > 0)
        {
            if (A[i] > A[i - 1] && op == '-')
            {
                res++;
                op = '.';
                continue;
            }
            else if (A[i] < A[i - 1] && op == '+')
            {
                res++;
                op = '.';
                continue;
            }
            if (A[i] > A[i - 1])
            {
                op = '+';
            }
            else if (A[i] < A[i - 1])
            {
                op = '-';
            }
        }
        else
            res++;
    }
    cout << res << endl;
    return 0;
}