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

class AHaiku {
public:
	void solve(istream& in, ostream& out) {
        string s; in >> s;
        rep(i,5) out << s[i];
        out << " ";
        for(int i = 6; i < 13; i++) out << s[i];
        out << " ";
        for(int i = 14; i < 19; i++) out << s[i];
        out << endl;
	}
};

int main() {
	AHaiku solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}