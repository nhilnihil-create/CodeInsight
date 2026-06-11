#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	deque<int> dq;
	rep(i,n){
		if(i%2==0) dq.push_back(a[i]);
		else dq.push_front(a[i]);
	}
	if(n%2==1) reverse(dq.begin(),dq.end());
	rep(i,n-1) cout << dq[i] << " ";
	cout << dq[n-1] << endl;

	return 0;
}