#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

const ll divide = 1e9 + 7;

ll factorial(ll num)
{
    ll sum = 1;
    for (int i = 1; i <= num; i++)
    {
        sum *= i;
        sum %= divide;
    }
    return (sum);
}

int main(void)
{
    int N, M;
    cin >> N >> M;

    ll ans = 0;
    ll temp;
    if (N == M)
    {
        temp = factorial(N);
        temp *= temp * 2;
        temp %= divide;
        ans = temp;
    }
    else if (abs(N - M) == 1)
    {
        ans = (factorial(N) * factorial(M) % divide);
    }
    else
    {
        ans = 0;
    }
    cout << ans << "\n";
    return (0);
}