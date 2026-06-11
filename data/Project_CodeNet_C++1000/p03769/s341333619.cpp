#include <bits/stdc++.h>

using namespace std;

int main() {

	long long n;
	scanf("%lld", &n);


	vector <int> a;

	while(n) {
		if(n%2==1) { //2*n+1
			a.push_back(0);
			n/=2;
		} else { // n+1
			a.push_back(1);
			n--;
		}
	}

	reverse(a.begin(), a.end());
	int cnt = 1;

	deque <int> ans;

	for (int i = 0; i < a.size(); ++i) {
		if(a[i] == 0) {
			ans.push_back(cnt++);
		} else {
			ans.push_front(cnt++);
		}
	}

	printf("%lu\n", 2*ans.size());
	for (int x: ans) {
		printf("%d ", x);
	}
	sort(ans.begin(), ans.end());
	for (int x: ans) {
		printf("%d ", x);
	}

}