#include <bits/stdc++.h>

using namespace std;

int arr[200005];
int bit[200005];

int main(){
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	
	for(int i = 1;i < 2*n;i++) cin >> arr[i];
	
	int low = -1; int high = 2*n+1;
	while(true){
		if(low == high - 1) break;
		int s = (low + high)/2;
		
		for(int i = 1;i < 2*n;i++){
			bit[i] = (arr[i] > s);
			//cout << bit[i] << " ";
		}
		//out << "\n";
		
		int res = -1;
		for(int d = 1;d < n;d++){
			if(bit[n+d-1] == bit[n+d]){
				res = bit[n+d];
				break;
			}
			if(bit[n-d+1] == bit[n-d]){
				res = bit[n-d];
				break;
			}
		}
		
		if(res == -1){
			res = ((bit[n] ^ (n&1)) ^ 1);
		}
		//cout << s << " " << res << "\n";
		if(res == 1) low = s;
		else high = s;
	}
	
	cout << high;
}