#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<iomanip>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1e9 + 7;
const int MAX = 1e9;
const ll LLMAX = 1e18;
const int INF = numeric_limits<int>::max();
const ll LLINF = numeric_limits<ll>::max();
const double PI = acos(-1.0);

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, a, n) for (int i = a; i <= (n); ++i)

int main() {
    int X; cin >> X;
    int A, B; cin >> A >> B;

    if (A >= B) {
        cout << "delicious" << endl;
    } else if (X - (B - A) >= 0) {
        cout << "safe" << endl;
    } else {
        cout << "dangerous" << endl;
    }
    
    return 0;
}
