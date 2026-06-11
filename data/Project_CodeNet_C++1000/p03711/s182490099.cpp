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

class AGrouping {
public:
	void solve(istream& in, ostream& out) {
        int x, y;
        in >> x >> y;
        if(x == 2 || y == 2) out << "No" << endl;
        else if((x == 1 || x == 3 || x == 5 || x == 7 || x == 8 || x == 10 || x == 12) && (y == 4 || y == 6 || y == 9 || y == 11)) {
            out << "No" << endl;
        }else if((y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12) && (x == 4 || x == 6 || x == 9 || x == 11)) {
            out << "No" << endl;
        }else{
            out << "Yes" << endl;
        }
	}
};

int main() {
	AGrouping solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}