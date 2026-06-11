#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll sumA = 0;
    ll opeA = 0;
    rep(i, n)
    {
        sumA += a[i];
        if (i % 2 == 0)
        {
            if (sumA <= 0)
            {
                opeA += abs(sumA) + 1;
                sumA += abs(sumA) + 1;
            }
        }
        else
        {
            if (sumA >= 0)
            {
                opeA += abs(sumA) + 1;
                sumA -= abs(sumA) + 1;
            }
        }
    }
    ll sumB = 0;
    ll opeB = 0;
    rep(i, n)
    {
        sumB += a[i];
        if (i % 2 == 0)
        {
            if (sumB >= 0)
            {
                opeB += abs(sumB) + 1;
                sumB -= abs(sumB) + 1;
            }
        }
        else
        {
            if (sumB <= 0)
            {
                opeB += abs(sumB) + 1;
                sumB += abs(sumB) + 1;
            }
        }
    }
    cout << min(opeA, opeB) << endl;
    return 0;
}