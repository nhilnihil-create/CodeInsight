#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define INF (int)1e09

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;
using std::pair;
using std::make_pair;
using std::min;
using std::max;
using std::string;
using std::vector;
using std::list;
using std::map;
using std::set; // insert erase find count
using std::queue;
using std::priority_queue;
using std::stack;

template <typename T> using Vec = vector<T>; // c++11
typedef pair<int, int> PII;
typedef pair<int, pair<int, int> > PIII;

int main(void) {
    int h;
    int w;
    cin >> h >> w;
    string s;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> s;
            if (s == "snuke") {
                cout << (char)(j + 'A') << i + 1 << endl;
            }
        }
    }
    return 0;
}

