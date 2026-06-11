#include <bits/stdc++.h>
     
using namespace std;

int main() {
	int N,L; cin >> N >> L;
	vector<int> a(N);
    for(auto&e:a) cin >> e;
	for(int i=1;i<N;++i) {
		if(a[i-1]+a[i]>=L) {
			cout << "Possible" << endl;
			for(int j=1;j<i;++j) cout << j << endl;
			for(int j=N-1;j>=i;--j) cout << j << endl;
			return 0;
		}
	}
	cout << "Impossible" << endl;
	
	return 0;
}
