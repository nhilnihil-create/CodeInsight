#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;
    double L, T;
    cin >> N >> L >> T;
    vector<int> X(N), W(N);
    rep(i, N)
    {
        cin >> X[i] >> W[i];
    }
    int count = 0;
    int one = 0;
    if (W[0] == 1)
    {
        rep(i, N)
        {
            if (W[i] != W[0])
            {
                double d = X[i] - X[0];
                count += (2 * (T - d / 2)) / L + 1;
            }
        }
    }
    else
    {
        rep(i, N)
        {
            if (W[i] != W[0])
            {
                double d = L - X[i] + X[0];
                count -= (2 * (T - d / 2)) / L + 1;
            }
        }
    }
    one += count;
    one %= N;
    if (one < 0)
    {
        one += N;
    }
    vector<int> ap(N);
    rep(i, N)
    {
        int position = ((int(X[i]) + int(T) * (3 - 2 * W[i]))) % int(L);
        if (position < 0)
        {
            position += L;
        }
        ap[i] = position;
    }
    int oneposition = ap[0];
    sort(ap.begin(), ap.end());
    int oneope = 0;
    rep(i, N)
    {
        if (ap[i] == oneposition)
        {
            if (i != N - 1)
            {
                if (W[0] == 1 && ap[i + 1] == oneposition)
                {
                    oneope = i + 1;
                    break;
                }
            }
            oneope = i;
            break;
        }
    }
    rep(i, N)
    {
        int index = (oneope - one + i) % N;
        if (index < 0)
        {
            index += N;
        }
        cout << ap[index] << endl;
    }
}