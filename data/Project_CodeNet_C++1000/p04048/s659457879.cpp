#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <numeric>
#include <functional>
#include <math.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define INF ((int)1e9)
#define INFLL ((ll)1e18)
#define MOD (1000000007LL)

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    ll N, X;
    cin >> N >> X;
    if (X > N-X) X = N-X;
    ll Tmp = X+N;
    ll L = N-2*X;
    while (L != 0) {
        if (X >= L) {
            if (X%L == 0) {
                Tmp += X+L*(2*X/L-1);
                break;
            } else {
                Tmp += X+2*L*(X/L)+X%L;
                ll nextX = X%L;
                ll nextL = L-X%L;
                X = nextX;
                L = nextL;
            }
        } else {
            if (L%X == 0) {
                Tmp += 2*L;
                break;
            } else {
                Tmp += 2*X*(L/X);
                L = L%X;
            }
        }
    }
    cout << Tmp << endl;

    return 0;
}
