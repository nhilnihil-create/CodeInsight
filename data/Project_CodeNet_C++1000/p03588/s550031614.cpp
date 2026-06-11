#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef pair<int,int> P;

int main() {
	int N;
	cin >> N;
	vector<P> AB(N);

	rep(i,N)
		cin >> AB.at(i).first >> AB.at(i).second;
	sort(AB.begin(), AB.end());

	cout << AB.at(N-1).first+AB.at(N-1).second << endl;
}