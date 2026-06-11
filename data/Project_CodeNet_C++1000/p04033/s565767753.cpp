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
    int a, b;
    cin >> a >> b;
    if (a > 0 && b > 0) cout << "Positive" << endl;
    else if ((a >= 0 && b <= 0) || (a <= 0 && b >= 0)) cout << "Zero" << endl;
    else {
        if (abs(a - b) % 2 == 0) cout << "Negative" << endl;
        else cout << "Positive" << endl;
    }
}
