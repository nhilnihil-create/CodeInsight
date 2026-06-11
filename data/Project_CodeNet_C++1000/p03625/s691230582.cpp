#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	for (int i=0; i<n; i++){
		cin >> arr[i];
	}
	sort (arr, arr+n);
	int x = arr[n-1];
	long long side = 1;
	int cnt = 0;
	for (int i=n-2; i>=0; i--){
		//cout << x << " " <<arr[i] << endl;
		if (arr[i]==x){
			side*=x;
			x = -1;
			cnt++;
			if (cnt==2){
				cout << side<< endl;
				return 0;
			}
		}
		else {
			x = arr[i];
		}
	}
	cout << 0 << endl;
}

//sort 之後取最大最後面的兩個以上的連續數字相乘


