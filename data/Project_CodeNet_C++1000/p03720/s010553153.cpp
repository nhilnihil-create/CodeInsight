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
    int N, M;
    cin >> N >> M;
    int a[M], b[M];
    for (int i = 0; i < M; i++)
    {
        cin >> a[i] >> b[i];
    }
    //map<int, int> x;
    int c[N + 1];
    fill(c, c + N + 1, 0);
    for (int i = 0; i < M; i++)
    {
        c[a[i]]++;
        c[b[i]]++;
    }
    for (int i = 1; i <= N; i++)
    {
        cout << c[i] << endl;
    }
    return 0;
}
