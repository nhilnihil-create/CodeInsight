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
    int N;
    cin >> N;
    vector<int> a;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    map<int, int> x;
    //int maxvalue = 0;
    int maxnum = 0;
    for (int i = 0; i < N; i++)
    {
        x[a[i]]++;
    }
    for (int i = 0; i < N; i++)
    {
        maxnum = max(maxnum, x[a[i] - 1] + x[a[i]] + x[a[i] + 1]);
    }

    cout << maxnum << endl;
    /*
    for (int i = 0; i < N; i++)
    {
        if (x[a[i]] == maxnum)
        {
            cout << x[a[i] - 1] + maxnum + x[a[i] + 1] << endl;
            return 0;
        }
    }*/
    return 0;
}
