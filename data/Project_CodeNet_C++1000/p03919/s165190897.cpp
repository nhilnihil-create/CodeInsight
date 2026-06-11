#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
#include <string>
#include <stack>
#include <tuple>
#include <queue>
#include <functional>
#include <unordered_map>
#include <random>
#include <iomanip>
#include <cstdlib>

using namespace std;
typedef long long ll;
ll MOD = 1e9 + 7;

int main()
{
    int height, width;
    cin >> height >> width;
    for (int row = 0; row < height; row++) for (int col = 0; col < width; col++)
    {
        string s;
        cin >> s;
        if (s == "snuke") cout << string(1,'A' + col) << row + 1 << endl;
    }
    return 0;
}