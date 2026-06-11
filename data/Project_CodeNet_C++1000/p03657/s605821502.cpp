#include <iostream>
#include <list>
#include <vector>
#include <cassert>
// #include <string>
// #include <algorithm>
// #include <numeric>
// #include <queue>
// #include <cmath>
// #include <set>
// #include <map>
// #include <iomanip>

#define MOD 1000000007
// #define INF 1000000001
#define S 100001

using namespace std;
typedef unsigned long long ull;
// typedef long long ll;

void p_() {
    cout << "\n";
}
template<class Head, class... Body>
void p_(Head head, Body... body) {
    cout << head << ",";
    p_(body...);
}


int main(int argc, char const *argv[]) {
    int A, B;
    cin >> A >> B;
    if (A % 3 == 0 || B % 3 == 0 || (A+B) % 3 == 0) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}
