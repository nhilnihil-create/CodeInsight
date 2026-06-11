#include <iostream>
using namespace std;

int main() {
	int arr[]={1,3,5,7,8,10,12};
	int arr2[]={4,6,9,11};
	int a, b;
	cin >> a >> b;
	int cnt=0;
	for (int i=0; i<7; i++){
		if (arr[i]==a) cnt ++;
		else if (arr[i]==b) cnt++;
	}
	if (cnt==2){ 
		cout << "Yes" << endl;
		return 0;
	}
	else cnt = 0;
	for (int i=0; i<4; i++){
		if (arr2[i]==a) cnt ++;
		else if (arr2[i]==b) cnt++;
	}
	if (cnt==2){
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}