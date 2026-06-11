#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <bitset>
#include <stack>
//#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
}

int main(void)
{
    int N;
    string s, t;
    cin >> N >> s >> t;
    int cnt = 0;
    if (s == t)
    {
        cout << N << endl;
        return 0;
    }
    else
    {
        int tmp = 0;
        int k = 0;
        for (int i = N; i < 2 * N; i++)
        {
            k = 0;
            for (int j = i - N; j < N; j++)
            {
                if (s[j] == t[k])
                {
                    tmp++;
                    k++;
                }
                else
                {
                    tmp = 0;

                    break;
                }
                cnt = max(cnt, tmp);
            }
        }
        cout << 2 * N - cnt << endl;
    }
    return 0;
}
