#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main()
{
    int64_t N, T;
    cin >> N >> T;
    int64_t t[N];
    for (int64_t i = 0; i < N; i++)
    {
        cin >> t[i];
    }
    int64_t total = 0;
    int64_t time = 0;
    for (int64_t i = 0; i < N - 1; i++)
    {
        if (t[i + 1] - t[i] >= T)
        {
            total += T;
            //            time += T;
        }
        else
        {
            total += t[i + 1] - t[i];
        }
    }
    total += T;
    cout << total << endl;
}