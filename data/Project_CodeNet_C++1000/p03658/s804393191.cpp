#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	vector<int> L;
	for (int i = 0; i < N; i++) {
		int l;
		cin >> l;
		L.push_back(l);
	}

	sort(L.begin(), L.end());
	reverse(L.begin(), L.end());

	int sum = 0;
	for (int i = 0; i < K; i++) {
		sum += L[i];
	}
	cout << sum << endl;
	
}
