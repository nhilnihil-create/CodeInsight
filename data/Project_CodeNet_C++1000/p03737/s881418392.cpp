#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cctype>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << (char)toupper(s1[0]) << (char)toupper(s2[0]) << (char)toupper(s3[0]) << '\n';
    return 0;
}
