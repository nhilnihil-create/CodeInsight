#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	for (int i=0; i<n; i++){
		cin>>arr[i];
	}
	sort(arr, arr+n);
	int z = 0;
	for (int i=0; i<n; i++){
		int cnt = 0;
		for (int j=0; j<n; j++){
			if (arr[j]==arr[i]) cnt++;
			else if (arr[j] ==arr[i]-1) cnt++;
			else if (arr[j]==arr[i]+1) cnt++;
		}
		//cout << cnt << endl;
		z = max(cnt, z);
	}
	cout << z;
	

}