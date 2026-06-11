#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N;
    cin >> N;
    map<int64_t, int64_t> hist;
    for (int64_t i = 1; i <= N; i++)
    {
        int M = i;
        int64_t a = 2;
        while (M >= a * a)
        {
            if (M % a == 0)
            {
                hist[a]++;
                M /= a;
            }
            else
                a++;
        }
        hist[M]++;
    }
    int64_t ans = 1;
    for (auto x : hist)
        if (x.first != 1)
            ans = ans * (x.second + 1) % mod;
    cout << ans;
}