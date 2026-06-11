#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <stack>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)
int main(void)
{
    string s;
    cin >> s;
    int left, right;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'A')
        {
            left = i;
            break;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'Z')
        {
            right = i;
        }
    }
    cout << right - left + 1 << endl;
    return 0;
}
