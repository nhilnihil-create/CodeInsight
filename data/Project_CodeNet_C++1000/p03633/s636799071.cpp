#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int64_t gcd(int64_t p, int64_t q)
{
    if (p < q)
        swap(p, q);

    if (p % q == 0)
        return q;
    else
        return gcd(q, p % q);
}

int main()
{
    int64_t N, tmp, ans = 1;
    cin >> N;
    for (int64_t i = 0; i < N; i++)
    {
        cin >> tmp;
        ans = (ans / gcd(ans, tmp)) * tmp;
    }
    cout << ans;
}