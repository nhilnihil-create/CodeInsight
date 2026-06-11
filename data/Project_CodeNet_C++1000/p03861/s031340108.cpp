#include <bits/stdc++.h>
using  namespace std;

int main(void)
{
    long long int a, b, x;

    cin >> a >> b >> x;

    long long int bn = b/x;
    long long int an = a/x;
    if (a%x == 0) cout << bn - an + 1 << endl;
    else cout << bn - an << endl;

    return 0;



}
