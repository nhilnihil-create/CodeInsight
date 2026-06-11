//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <climits>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <random>
#include <complex>
#include <regex>

using namespace std;

#define C_MAX(a, b) ((a)>(b)?(a):(b))
#define SHOW_VECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOW_MAP(v){std::cerr << #v << endl; for(const auto& xxx: v){std::cerr << xxx.first << " " << xxx.second << "\n";}}

bool isOK(long long N, long long A, long long B, long long mid, vector<long long> h) {
    for (int i = 0; i < N; i++) h[i] -= (B * mid);
    long long count = 0;
    long long diff = A - B;
    for (int i = 0; i < N; i++) {
        if (h[i] > 0) {
            count += h[i] / diff;
            if (h[i] % diff) count++;
        }
    }
    return count <= mid;
}

int main() {

    long long N, A, B;
    cin >> N >> A >> B;

    vector<long long> h(N);
    for (int i = 0; i < N; i++) cin >> h[i];

    long long ng = -1LL;
    long long ok = 1000000001LL;

    while (abs(ok - ng) > 1) {
        long long mid = (ng + ok) / 2LL;
        if (isOK(N, A, B, mid, h)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;

    return 0;
}


















































































