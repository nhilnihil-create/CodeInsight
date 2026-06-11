#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int digit(ll n)
{
    int res = 0;
    while (n > 0)
    {
        res++;
        n /= 10;
    }
    return res;
}

int main()
{
    ll N;
    cin >> N;

    ll a = sqrt(N);

    while (N % a != 0)
    {
        a--;
    }

    cout << digit(N / a) << endl;
    return 0;
}