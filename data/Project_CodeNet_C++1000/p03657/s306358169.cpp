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
    int a, b;
    cin >> a >> b;
    if((a+b)%3 == 0 || a % 3 == 0 || b % 3 == 0)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}
