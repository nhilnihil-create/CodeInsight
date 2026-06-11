#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int k,t;
	cin >> k >> t;
	vector<int> a(t);
	int m = 0;
	rep(i,t){
		cin >> a[i];
	}
	sort(a.rbegin(),a.rend());
	int ans = a[0] - 1;
	REP(i,t-1){
		ans -= a[i];
	}
	cout << max(ans, 0) << endl;
    return 0;
}

