#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <utility>
#include <iomanip>
#include <numeric>
#include <climits>
#include <algorithm>
#include <cstdint>
using namespace std;

int main()
{
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    for (int i = 0; i < str.length() - 1; i++)
        if (str[i] == str[i + 1])
        {
            cout << "no";
            return 0;
        }
    cout << "yes";
}