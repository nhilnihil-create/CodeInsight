#include <iostream>
#include <algorithm>
using namespace std;
long long int s[100001];
int main()
{
    long long int n, a, b, sum = 0;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 2; i <= n; i++)
    {
        long long int m = (s[i] - s[i - 1]) * a;
        sum += min(m, b);
    }
    cout << sum << endl;
}