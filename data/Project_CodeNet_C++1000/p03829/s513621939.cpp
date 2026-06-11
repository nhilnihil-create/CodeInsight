#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#include <iomanip>
#define ll long long int
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
int mx2[] = {1,0};
int my2[] = {0,1};

class DWalkAndTeleport {
public:
	void solve(istream& in, ostream& out) {
        int n; ll a, b,ans = 0;
        in >> n >> a >> b;
        vector<ll> x(n),sa(n-1);
        rep(i,n) in >> x[i];
        rep(i,n-1) sa[i] = x[i+1] - x[i];

        rep(i,n-1) {
            if(sa[i] * a >= b) ans += b;
            else ans += sa[i] * a;
        }
        out << ans << endl;
	}
};

int main() {
	DWalkAndTeleport solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}