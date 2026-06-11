#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
    string ans = "NO";
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = i; i <= b; ++i)
    {
        int t = a * i;
        if (t % b == c)
        {
            ans = "YES";
        }
    }
    cout << ans << endl;
}