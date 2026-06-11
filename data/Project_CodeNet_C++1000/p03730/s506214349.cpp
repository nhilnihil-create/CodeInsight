#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    for (int i = a; i <= a * b; i += a)
    {
        if (i % b == c)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
