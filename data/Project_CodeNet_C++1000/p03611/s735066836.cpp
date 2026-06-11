#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
	int N;
	cin >> N;
	vector<int> A( N );
	for( auto &x : A ) {
		cin >> x;
	}
	map<int,int> search;
	for (auto &x : A) {
		search[ x ]++;
		search[ x + 1 ]++;
		search[ x - 1 ]++;
	}
	int result{};
	for(auto x : search) {
		result = max(result, x.second);
	}
	cout << result << endl;

	return 0;
}
