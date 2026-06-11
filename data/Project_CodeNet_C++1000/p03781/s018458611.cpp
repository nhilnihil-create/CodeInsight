#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int x, ans;
	cin >> x;
	int s = 0;
	for(int i = 1; i <= x; i++){
		s += i;
		if(s >= x){
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
