#include <bits/stdc++.h>
using namespace std;
int main(){
	
	char arr[16];
	for(int i = 0 ; i<16 ; i++){
		cin >> arr[i];
	}
	
	int ans = 0;
	
	if(arr[0] != 'C'){
		ans++;
	}
	if(arr[1] != 'O'){
		ans++;
	}
	if(arr[2] != 'D'){
		ans++;
	}
	if(arr[3] != 'E'){
		ans++;
	}
	if(arr[4] != 'F'){
		ans++;
	}
	if(arr[5] != 'E'){
		ans++;
	}
	if(arr[6] != 'S'){
		ans++;
	}
	if(arr[7] != 'T'){
		ans++;
	}
	if(arr[8] != 'I'){
		ans++;
	}
	if(arr[9] != 'V'){
		ans++;
	}
	if(arr[10] != 'A'){
		ans++;
	}
	if(arr[11] != 'L'){
		ans++;
	}
	if(arr[12] != '2'){
		ans++;
	}
	if(arr[13] != '0'){
		ans++;
	}
	if(arr[14] != '1'){
		ans++;
	}
	if(arr[15] != '6'){
		ans++;
	}
	
	cout << ans; 

	return 0;
}
