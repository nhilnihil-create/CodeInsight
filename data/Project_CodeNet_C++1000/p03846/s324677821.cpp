#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    long long n; cin >> n;
    map<long long, long long> dict;

    long long e;
    bool flg = true;
    while (cin >> e) {
        ++dict[e];
    }

    for (long long i = (n & 1) + 1; i < n; i += 2) {
        if (dict[i] != 2) {
            flg = false;
            break;
        }
    }
    if (n & 1 == 0 && dict[0] != 1) {
        flg = false;
    }
    long long ans = 1;
    for(int i = 0; i < n / 2; ++i) {
        ans = (ans << 1)% 1000000007ll ;
    }

    cout << (flg ? ans : 0 )<< endl;
}
