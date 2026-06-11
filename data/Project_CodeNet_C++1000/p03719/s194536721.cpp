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
    int a, b, c;
    cin >> a >> b >> c;
    if(c >= a && c <= b)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;


    return 0;
}
