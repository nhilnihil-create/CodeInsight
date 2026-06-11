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
    string a, b, c;
    cin >> a >> b >> c;
    int len1 = a.length();
    int len2 = b.length();
    if(a[len1-1] == b[0] && b[len2-1] == c[0])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;


    return 0;
}
