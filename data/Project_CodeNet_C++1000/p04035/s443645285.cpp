#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;

int main(){
	int N;
	LL L;
	cin >> N >> L;
	vector<LL> a(N);
	rep(i,N) cin >> a[i];
	LL M=0, num=0;
	rep(i,N-1){
		if(M<a[i]+a[i+1]){
			M=a[i]+a[i+1];
			num=i;
		}
	}
	if(M<L) cout << "Impossible" << endl;
	else{
		cout << "Possible" << endl;
		rep(i,num) cout << i+1 << endl;
		for(int i=N-1; i>num+1; i--) cout << i << endl;
		cout << num+1 << endl;
	}

	return 0;
}