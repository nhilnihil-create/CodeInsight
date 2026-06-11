#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <stack>
//#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)
int main(void)
{
    lli Q, H, S, D;
    cin >> Q >> H >> S >> D;
    lli N;
    cin >> N;
    Q *= 4;
    H *= 2;
    lli lit1 = min(Q, min(H, S));
    lli price = 0;
    if (2 * lit1 <= D)
    {
        cout << lit1 * N << endl;
    }
    else
    {
        cout << (int)(N / 2) * D + (N % 2) * lit1 << endl;
    }
    return 0;
}
