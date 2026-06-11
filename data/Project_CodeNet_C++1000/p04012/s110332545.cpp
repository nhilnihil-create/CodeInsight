#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 100000000;
typedef pair<int, int> P;
const int MAX_N = 1000000;

string w;
vector<int> alpha(26,0);

int main() {
	cin >> w;
	rep(i, w.size()) {
		char c;
		c = w.at(i);
		int tmp;
		tmp = c - 'a';
		alpha.at(tmp)++;
	}
	rep(i, 26) {
		if (alpha.at(i)%2 !=0)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	
	cout << "Yes" << endl;
	return 0;
}