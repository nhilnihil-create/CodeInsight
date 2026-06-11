#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 100000000;
typedef pair<int, int> P;



int main() {
	string S;
	cin >> S;
	rep(i, S.size()) {
		for (int j = i+1; j < S.size(); j++)
		{
			if (S.at(i) == S.at(j)) {
				cout << "no" << endl;
				return 0;
			}
		}
	}
	cout << "yes" << endl;
	return 0;
}