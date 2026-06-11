#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int main()
{
    ll n;
    cin >> n;
    vector<ll> T(n), A(n);
    rep(i, n) cin >> T[i] >> A[i];
    ll sumT = T[0];
    ll sumA = A[0];
    for (int i = 1; i < n; i++)
    {
        ll nt1, na1, nt2, na2;
        //Tを基準にした新しい値1
        if (sumT % T[i] == 0)
        {
            nt1 = sumT;
            na1 = (sumT / T[i]) * A[i];
        }
        else
        {
            nt1 = ((sumT / T[i]) + 1) * T[i];
            na1 = ((sumT / T[i]) + 1) * A[i];
        }
        //Aを基準にした新しい値2
        if (sumA % A[i] == 0)
        {
            na2 = sumA;
            nt2 = (sumA / A[i]) * T[i];
        }
        else
        {
            na2 = ((sumA / A[i]) + 1) * A[i];
            nt2 = ((sumA / A[i]) + 1) * T[i];
        }

        if (nt1 < sumT || na1 < sumA)
        {
            sumT = nt2;
            sumA = na2;
        }
        else
        {
            sumT = nt1;
            sumA = na1;
        }
    }
    cout << sumT + sumA << endl;
}