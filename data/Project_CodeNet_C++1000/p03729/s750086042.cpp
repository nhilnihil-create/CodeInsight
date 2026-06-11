#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;            //

int main(void)
{
    string A, B, C;
    cin >> A >> B >> C;

    if (A[A.size() - 1] == B[0] && B[B.size() - 1] == C[0])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return (0);
}