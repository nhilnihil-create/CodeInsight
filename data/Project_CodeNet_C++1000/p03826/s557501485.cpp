#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 1999999999
#define MODA 1000000007

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int side1 = a * b;
    int side2 = c * d;
    if(side1 > side2)
        cout << side1 << endl;
    else
        cout << side2 << endl;

    return 0;
}
