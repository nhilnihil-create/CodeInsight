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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> backet(1e6, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        backet[a[i]]++;
        backet[a[i] + 1]++;
        if(a[i])
        backet[a[i] - 1]++;
    }
    int ans = 0;
    for (int i = 0; i < 1e6; i++) {
        if (backet[i] == 0) continue;
        ans = max(ans, backet[i]);
    }
    cout << ans << endl;
}
