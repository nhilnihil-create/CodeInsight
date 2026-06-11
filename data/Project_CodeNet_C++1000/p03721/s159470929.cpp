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
    lli N, K;
    cin >> N >> K;
    vector<pair<lli, lli>> tasks;
    lli a, b;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        tasks.emplace_back(a, b);
    }
    sort(tasks.begin(), tasks.end());
    lli sum = 0;
    for (auto i : tasks)
    {
        sum += i.second;
        if (sum >= K)
        {
            cout << i.first << endl;
            return 0;
        }
    }
    return 0;
}
