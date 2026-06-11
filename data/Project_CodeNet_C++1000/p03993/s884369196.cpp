#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <deque>
#include <queue>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)
struct Pair
{
    int I;
    int U;
};
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
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[a[i] - 1] == i + 1)
        {
            count++;
        }
    }
    cout << count / 2 << endl;
    return 0;
}