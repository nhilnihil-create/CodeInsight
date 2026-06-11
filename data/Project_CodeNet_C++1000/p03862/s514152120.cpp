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
#define ll long long int
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
int mx2[] = {1,0};
int my2[] = {0,1};

class CBoxesAndCandies {
public:
	void solve(istream& in, ostream& out) {
        ll n,x,ans = 0;
        in >> n >> x;
        vector<ll> a(n);
        rep(i,n) in >> a[i];
        rep(i,n-1){
            ll check = a[i] + a[i+1] - x;
            if(check > 0){
                ans += check;
                if(a[i+1] >= check) a[i+1] -= check;
                else a[i+1] = 0;
            }
        }
        out << ans << endl;
	}
};

int main() {
	CBoxesAndCandies solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}