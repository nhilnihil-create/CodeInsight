#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n;

int main(void){
	cin >> n;
	vector<lli> a(n+1);
	deque<lli> b;
	rep(i, n) cin >> a[i];
	rep(i, n){
		if(i%2 == (n-1)%2) b.push_front(a[i]);
		else b.push_back(a[i]);
	}
	rep(i, n) cout << b[i] << " ";
	cout << endl;
	return 0;
}
