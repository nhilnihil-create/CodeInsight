#include <bits/stdc++.h>

using namespace std;

int main() {
	int N; cin >> N;
	vector<int> p(N),a(N),b(N);
	for(auto&e:p) cin >> e;
	for(int i=0;i<N;++i) a[i]=i*N+1,b[i]=(N-i)*N+1;
	for(int i=0;i<N;++i) a[p[i]-1]+=i;
	for(int i=0;i<N;++i) {
		if(i) cout << " ";
		cout << a[i];
	}
	cout << endl;
	for(int i=0;i<N;++i) {
		if(i) cout << " ";
		cout << b[i];
	}
	cout << endl;
	
	return 0;
}
