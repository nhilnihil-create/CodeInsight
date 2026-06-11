#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
using namespace std;
using LL = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < n; i++)
const int INF = numeric_limits<int>::infinity();

int main(void)
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i+=2){
        putchar(s[i]);
    }
    putchar('\n');

    return 0;
}