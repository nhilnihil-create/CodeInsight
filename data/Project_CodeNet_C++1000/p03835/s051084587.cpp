#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <stack>
#include <queue>
//#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)

//input
int main(void)
{
    lli K, S;
    cin >> K >> S;
    lli cnt = 0;
    for (int x = 0; x <= K; x++)
    {
        for (int y = 0; y <= K; y++)
        {
            if (0 <= S - x - y && S - x - y <= K)
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
