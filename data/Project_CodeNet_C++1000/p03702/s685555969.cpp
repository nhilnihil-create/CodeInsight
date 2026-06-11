#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
using ll = long long;
//西暦⇒時代の歴

ll h[100010];
int N;
ll A, B;
bool check(ll n)
{
    ll t = 0;
    for (int i = 0; i < N; ++i)
    {
        if (max(0LL, h[i] - B * n) % (A - B) == 0)
        {
            t += max(0LL, h[i] - B * n) / (A - B);
        }
        else
        {
            t += max(0LL, h[i] - B * n) / (A - B) + 1;
        }
    }
    if (t <= n)
        return true;
    else
        return false;
}
int main()
{

    cin >> N;

    cin >> A >> B;

    for (int i = 0; i < N; ++i)
    {
        cin >> h[i];
    }

    ll lb = -1, ub = 10000000000 - 1;

    while (ub - lb > 1)
    {
        ll mid = (lb + ub) / 2;
        if (check(mid))
        {
            ub = mid;
        }
        else
        {
            lb = mid;
        }
        //cout << lb << " " << ub << endl;
    }
    cout << ub << endl;
    return 0;
}