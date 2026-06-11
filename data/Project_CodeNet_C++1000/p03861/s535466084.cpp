#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>

#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

int main() {
    uint64_t a, b, x;
    cin >> a >> b >> x;

    uint64_t divA = a / x;
    uint64_t divB = b / x;
//    cout << divA << " " << divB <<  " " << divB - divA << endl;
    int ret = 0;
    if(a%x == 0) {
        ret = 1;
    }

    cout << divB - divA + ret << endl;

}
