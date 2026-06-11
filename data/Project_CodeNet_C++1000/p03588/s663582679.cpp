#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

main(){
	int n;
	ll a,b;

	cin >> n;

	ll ans = 1e10;
	for(int i=0;i<n;i++){
		cin >> a >> b;
		ans = min(a+b,ans);
	}

	cout << ans << endl;

	return 0;
}
