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
    if (s.front() == s.back()) {
        if (s.length() % 2) cout << "Second" << endl;
        else cout << "First" << endl;
    }
    else {
        if (s.length() % 2) cout << "First" << endl;
        else cout << "Second" << endl;
    }
    return 0;
}
