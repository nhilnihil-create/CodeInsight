#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int x, a, b;
    cin >> x >> a >> b;
    int disa = abs(x - a);
    int disb = abs(x - b);
    if (disa < disb)
        cout << "A" << endl;
    else
        cout << "B" << endl;
    return 0;
}