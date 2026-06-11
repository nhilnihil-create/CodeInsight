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


long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}


int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a % 2 == 0 && b%2==0 && c%2==0) {
        if (a == b && b == c) {
            cout << -1 << endl;
            return 0;
        }
        int cnt = 0;
        while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
            int bufa = a / 2,bufb = b/2,bufc = c/2;
            a = bufb + bufc;
            b = bufa + bufc;
            c = bufa + bufb;
            cnt++;
        }
        cout << cnt << endl;
        return 0;
    }
    else  cout << 0 << endl;
}
