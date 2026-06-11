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
    int a1 = a + b;
    int a2 = a + c;
    int a3 = b + c;
    int res = min(a1, min(a2, a3));
    cout << res << endl;


    return 0;
}
