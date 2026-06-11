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
    int n;
    cin >> n;
    Vec<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    long long int count = v[0] - 1;
    long long int min_num = 2;

    //cout << "I = 0" << ", " << count << endl;
    for (int i = 1; i < n; i++) {
        if (v[i] == min_num) {
            min_num++;
            continue;
        } else if (v[i] < min_num) {
            continue;
        } else {
            count += (v[i] / min_num);
            if (v[i] % min_num == 0) {
                count--;
            }
        }
        //cout << "I = " << i << ", " << count << endl;
    }
    cout << count << endl;

    return 0;
}

