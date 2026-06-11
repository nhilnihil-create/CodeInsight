#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i=0; i<n; i++){
		cin>> arr[i];
	}
	for (int i=n-1; i>=0; i-=2){
		cout << arr[i]<<' ';
	}
	if (n%2==0){
		for (int i=0; i<n; i+=2){
			cout << arr[i]<<' ';
		}
	}
	else{
		for (int i=1; i<n; i+=2){
			cout << arr[i]<<' ';
		}		
	}	
	cout << endl;
}
