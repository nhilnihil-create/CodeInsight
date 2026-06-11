#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int main(void)
{
    long long a, b, x;
    cin >> a >> b >> x;

    long long pa = a / x;
    long long qa = a % x;

    long long pb = b / x;

    long long ans = pb - pa;

    if(qa == 0)
    {
        ans++;
    }

    cout << ans << endl;
}