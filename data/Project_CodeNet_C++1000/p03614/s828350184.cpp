/*input
3
1 2 3
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	int arr[n];
	int i;
	for(i=0;i<n;++i)
		cin >> arr[i];
	int ct = 0;
	for(i=0;i<n-1;++i){
		if(arr[i] == i+1){
			swap(arr[i],arr[i+1]);
			ct++;
		}
	}
	if(arr[n-1] == n){
		ct++;
	}
	cout << ct << endl;
	return 0;
}