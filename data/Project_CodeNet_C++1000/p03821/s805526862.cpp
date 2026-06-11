#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;

int main(){
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> b(n);
	ll now=0;
	rep(i,n){
		cin >> a[i] >> b[i];
	}
	for(int i=a.size()-1;i>=0;i--){
		a[i]+=now;
		if(a[i]%b[i]==0);
		else now+=(a[i]/b[i]+1)*b[i]-a[i];
	}
	cout << now << endl;
	return 0;
}
