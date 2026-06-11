#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <bitset>
#include <iomanip>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;

int main()
{
    int num[110] = {};
    int a, b, c;
    int ans = 0;
    
    cin >> a >> b >> c;

    num[a]++; num[b]++; num[c]++;

    for (int i = 0; i <= 100; i++) {
        if (num[i] > 0) {
            ans++;
        }
    }

    cout << ans << endl;
}
