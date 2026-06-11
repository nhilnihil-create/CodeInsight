#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);

    int n;
    long long K;
    cin >> n >> K;
    map<int, long long> cnts;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        cnts[a] += b;
    }

    int res = -1;
    for (auto& p : cnts) {
        if (K <= p.second) {
            res = p.first;
            break;
        } else {
            K -= p.second;
        }
    }

    cout << res << '\n';


    return 0;
}