#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
typedef pair<int, int> P;
typedef int64_t ll;
const int MAX_N = 10000;
const int INF = 1000000000;

int N;

int main() {
	vector<int> fac = { 2,4,8,16,32,64 };
	cin >> N;
	for ( int i = fac.size()-1; i >=0; i--)
	{
		if (fac.at(i) <= N) {
			cout << fac.at(i) << endl;
			return 0;
		}
	}
	cout << 1 << endl;
	return 0;
}