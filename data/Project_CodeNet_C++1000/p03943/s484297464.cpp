#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int maxn = max({a, b, c}), sum = a + b + c;
    if (sum == 2 * maxn)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}