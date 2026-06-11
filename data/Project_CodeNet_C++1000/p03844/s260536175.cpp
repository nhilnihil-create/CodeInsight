#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    char c;
    cin >> a >> c >> b;
    if(c == '-')
        cout << a - b;
    else
        cout << a + b;

    return 0;
}
