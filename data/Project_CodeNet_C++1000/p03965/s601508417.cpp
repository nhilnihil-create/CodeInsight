#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <array>
#include <algorithm>
#include <numeric>
#include <limits>
#include <string>
#include <regex>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    int score = 0;
    for (int i = 0; i < s.length(); i++) {
        if (i % 2 == 0 && s[i] == 'p') score--;
        else if (i % 2 == 1 && s[i] == 'g') score++;
    }
    cout << score << endl;

    return 0;
}
