#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)
int main(void)
{
    int N, T;
    cin >> N >> T;
    vector<lli> t;
    lli tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        t.push_back(tmp);
    }
    lli *x;
    x = new lli[N - 1];
    for (int i = 0; i < N - 1; i++)
    {
        x[i] = t[i + 1] - t[i];
    }
    lli sum = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (x[i] > T)
        {
            sum += T;
        }
        else
        {
            sum += x[i];
        }
    }
    cout << sum + T << endl;
    return 0;
}