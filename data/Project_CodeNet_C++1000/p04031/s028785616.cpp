#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

void solve() {
	int n,p,total=0;
	cin >> p;
	
	vector<int> list;
	
	while(p--) {
		cin >> n;
		total += 2*n;
		list.push_back(n);		
	}
 	
 	int val = round((double)total/(double)(list.size()*2));
 	//cout << val << endl;
 	int ans = 0;
 	for(int x: list) {
		ans += pow(val-x,2);
	}
 	
	cout << ans;
 	
 	
}
		
			
		

int32_t main() {
	IOS;
	solve();
	return 0;
}
