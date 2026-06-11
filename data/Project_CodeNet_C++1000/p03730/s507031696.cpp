#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include<iomanip>
#include<functional>

using namespace std;
typedef long long ll;

// a と b の最大公約数を返す関数
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    bool ans = false;
    for (int i = A; i <= B * A; i += A) {
        if (i % B == C) {
            ans = true;
        }
    }
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}
