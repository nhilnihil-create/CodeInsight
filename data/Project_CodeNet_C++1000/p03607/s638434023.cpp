#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <bitset>
using namespace std;
typedef long long int lli;
int main(void)
{
    map<int, int> x;
    int N;
    cin >> N;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        x[tmp]++;
    }
    int ans = 0;
    for (map<int, int>::iterator i = x.begin(); i != x.end(); ++i)
    {
        if (i->second % 2 == 1)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
