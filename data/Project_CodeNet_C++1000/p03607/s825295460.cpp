#include <iostream>
#include <utility>
#include <map>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;

int main(void) {
    map<Int, Int> mp;
    Int n;
    cin >> n;
    Int a;
    for (Int i = 0; i < n; ++i) {
        cin >> a;
        if (mp.count(a) == 0) {
            mp.insert(make_pair(a, 1));
        } else {
            mp.erase(a);
        }
    }
    cout << mp.size() << endl;
    return 0;
}

