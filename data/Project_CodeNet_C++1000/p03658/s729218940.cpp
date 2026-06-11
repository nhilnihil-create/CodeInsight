#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;

	vector<int> sticks(n);

	for(int i = 0; i < n; i++){
		int l;
		cin >> l;
		sticks.push_back(l);
	}

	sort(sticks.begin(), sticks.end(), greater<int>());

	int length = 0;
	for(int i = 0; i < k; i++){
		length += sticks[i];
	}

	cout << length << endl;
}
