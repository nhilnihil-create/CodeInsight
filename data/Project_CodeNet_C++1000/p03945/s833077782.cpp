#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    string S;
    cin >> S;

    int ans = 0;
    for (int i = 0; i < S.size() - 1; i++)
    {
        if (S[i] != S[i + 1])
        {
            ans++;
        }
    }
    cout << ans << endl;
}