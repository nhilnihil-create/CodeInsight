#include <bits/stdc++.h> 

using namespace std;

int main() {

	vector<int> vec;

	for (int i = 0; i < 3; i++) {

		int a; scanf("%d", &a);
		vec.push_back(a);

	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	printf("%d", vec.size());

	return 0;

}