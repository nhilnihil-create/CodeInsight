#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <limits>
#include <climits>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main()
{
    string O, E;
    cin >> O;
    cin >> E;

    if (O.size() == E.size()) {
        for (int i = 0; i < E.size(); ++i) {
            cout << O[i] << E[i];
        }
        cout << endl;
    }
    else if (O.size() > E.size()) {
        for (int i = 0; i < E.size(); ++i) {
            cout << O[i] << E[i];
        }
        cout << O[O.size()-1] << endl;
    } else {
        for (int i = 0; i < O.size(); ++i) {
            cout << O[i] << E[i];
        }
        cout << E[E.size()-1] << endl;
    }

    return 0;
}
