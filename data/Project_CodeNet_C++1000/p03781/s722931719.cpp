#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int x;
    int ans = 0, cnt = 0;

    cin >> x;

    for (int i = 1; i <= x; i++) {
        ans += i;
        cnt++;
        if (ans >= x) break;
    }

    cout << cnt << endl;
}
