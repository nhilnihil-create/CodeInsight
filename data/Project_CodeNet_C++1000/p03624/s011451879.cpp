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
    map<char, int> x;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        x[s[i]]++;
    }
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (x[c] == 0)
        {
            cout << c << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}
