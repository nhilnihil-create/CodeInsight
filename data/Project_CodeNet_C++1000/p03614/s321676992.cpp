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

#define SHOW_VECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOW_MAP(v){std::cerr << #v << endl; for(const auto& xxx: v){std::cerr << xxx.first << " " << xxx.second << "\n";}}

int main() {

    int N;
    cin >> N;

    vector<int> p(N);
    for (int i = 0; i < N; i++) cin >> p[i], p[i]--;

    vector<bool> b(N, false);
    for (int i = 0; i < N; i++) b[i] = (p[i] == i);

    int ans = 0;
    for (int i = 0; i < N - 1; i++) if (b[i]) ans++, b[i] = b[i + 1] = false;
    if (b.back()) ans++;

    cout << ans << endl;

    return 0;
}









































































