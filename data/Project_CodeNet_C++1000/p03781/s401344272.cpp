#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric> 
#include <math.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define INF 999999999
using namespace std;

int main()
{
    int x;
    cin >> x;
    x = abs(x);
    int ans = 0;
    int i = 1;
    while(true) {
        if(x <= 0) {
            break;
        }
        x = x - i;
        ans += 1;
        i++;
    }

    cout << ans << endl;
    return 0;
}
