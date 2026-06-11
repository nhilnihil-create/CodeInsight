#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <sys/time.h>
#include <tuple>
#include <random>
using namespace std;

#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define UNIQ(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef complex<double> comp;
typedef vector< vector<ld> > matrix;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};
const int inf = 1e9 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    
    
    ll n;
    char ans;
    n = 1e12;
    cout << "? " << n << endl; cout.flush();
    cin >> ans;
    if (ans == 'Y') {
        n = 10;
        while (true) {
            cout << "? " << n-1 << endl; cout.flush();
            cin >> ans;
            if (ans == 'Y') break;
            n *= 10;
        }
        cout << "! " << n/10 << endl; cout.flush();
    } else {
        n = 10;
        while (true) {
            cout << "? " << n << endl; cout.flush();
            cin >> ans;
            if (ans == 'N') break;
            n *= 10;
        }
    
        ll lb = n/10, ub = n;
        while (ub - lb > 1) {
            int mid = (ub + lb) / 2;
            cout << "? " << mid << "0" << endl; cout.flush();
            cin >> ans;
            if (ans == 'N') {
                lb = mid;
            } else {
                ub = mid;
            }
        }
        cout << "! " << ub << endl; cout.flush();
    }
}
