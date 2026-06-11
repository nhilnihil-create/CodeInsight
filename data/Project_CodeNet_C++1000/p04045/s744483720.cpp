#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

vector<bool> ketawa(int64_t N)
{
    vector<bool> list(10);
    int64_t d = 0;
    while (N != 0)
    {
        list[N % 10] = true;
        N /= 10;
    }
    return list;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> list(10);
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        list[tmp] = true;
    }

    while (true)
    {
        auto x = ketawa(N);
        bool y = true;
        for (int i = 0; i < 10; i++)
            if (x[i] && list[i])
                y = false;
        if (y)
        {
            cout << N;
            break;
        }
        N++;
    }
}