#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <numeric>
#include <algorithm>
#include <utility>

// 14:01



using std::cout;
using std::cin;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


int main() {
    int task = 1;
//    cin >> task;

    while (task--) {
        int x, a, b;
        cin >> x >> a >> b;
        if (b <= a) {
            cout << "delicious" << "\n";
            continue;
        }
        if (b - a > x) {
            cout << "dangerous" << "\n";
        } else {
            cout << "safe" << "\n";
        }

    }

    return 0;
}