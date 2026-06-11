#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <climits>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

using int64 = long long;
using P = pair<char,int>;


int main() {
    string s;
    cin >> s;

    vector<P> len;
    len.emplace_back(s.front(), 0);
    for (auto c : s) {
        if (len.back().first == c) len.back().second++;
        else len.emplace_back(c, 1);
    }

    cout << len.size() - 1 << endl;
}