#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
// #include <queue>
// #include <cmath>
// #include <string>
// #include <set>
// #include <map>
// #include <iomanip>

// #define MOD 1000000007
// #define INF 1000000001

using namespace std;
// typedef unsigned long long ull;
typedef long long ll;

void p_() {
    cout << "\n";
}
template<class Head, class... Body>
void p_(Head head, Body... body) {
    cout << head << ",";
    p_(body...);
}


int main(int argc, char const *argv[]) {
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    cout << v[0] + v[1] << endl;
    return 0;
}
