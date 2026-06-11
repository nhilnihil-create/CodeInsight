#include <iostream> 
#include <cstdio> 
#include <cstdlib>  
#include <algorithm> 
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <tuple>
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
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = 0;
    if (a == b) cout << 1 << endl;
    else if (n == 1) cout << 0 << endl;
    else if (a > b) cout << 0 << endl;
    else if (n == 2) cout << 1 << endl;
    else cout << b * (n - 2) - a * (n - 2) + 1 << endl;

}
