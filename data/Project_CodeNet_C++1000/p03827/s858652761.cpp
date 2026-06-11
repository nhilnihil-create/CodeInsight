#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 100000000;
typedef pair<int, int> P;

int N, x = 0,tmp=0;
string S;

int main() {
	cin >> N >> S;
	rep(i, N) {
		if (S.at(i) == 'I') tmp++;
		if (S.at(i) == 'D')tmp--;
		x = max(x, tmp);
	}
	cout << x << endl;
}