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

class AShiritori {
public:
	void solve(istream& in, ostream& out) {
        string a,b,c;
        in >> a >> b >> c;
        int na = a.size(),nb = b.size();
        if(a[na - 1] == b[0] && b[nb - 1] == c[0]) out << "YES" << endl;
        else out << "NO" << endl;
	}
};

int main() {
	AShiritori solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}