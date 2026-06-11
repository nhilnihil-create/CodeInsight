#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int ans[N*N];

int main(){
	int n;
	cin >> n;
	
	vector <int> v(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
		v[i]--;
	}


	vector <pair<int, int> > vz; // pos, val
	for (int i = 0; i < n; ++i) {
		vz.push_back(make_pair(v[i], i+1));
		ans[v[i]] = i+1;
	}

	sort(vz.begin(), vz.end());
	int nn = vz.size();
	for (int i = 0; i < nn; ++i) {
		int cnt = vz[i].second - 1;
		for (int k = 0; k < n*n; ++k) {
			if(ans[k] == 0 && k < vz[i].first && cnt) { // k < vz[i].first
				ans[k] = vz[i].second;
				cnt--;
			}	
		}
	}



	reverse(vz.begin(), vz.end());

	for (int i = 0; i < nn; ++i) {
		int cnt = n - vz[i].second;
		for (int k = n*n-1; k >= 0; --k) {
			if(ans[k] == 0 && k > vz[i].first && cnt) { // k < vz[i].first
				ans[k] = vz[i].second;
				cnt--;
			}	
		}
	}
	int ok = 1;
	for (int i = 0; i < n*n; ++i) {
		if(ans[i] == 0) ok = 0;
	}
	if (ok) {
		puts("Yes");
		for (int i = 0; i < n*n; ++i) {
			printf("%d ", ans[i]);
		}
	printf("\n");
	}
	else puts("No");
	

}