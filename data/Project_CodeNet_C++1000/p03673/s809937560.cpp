#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i=0; i<n; i++){
		cin>> arr[i];
	}
    if (n%2==0){
      for (int i=n-1; i>=0; i--){
          if (i%2==1) cout << arr[i]<<' ';
      }
      for (int i=0; i<n; i++){
          if (i%2==0) cout << arr[i]<<' ';
      }
    }
  	else{ 
      for (int i=n-1; i>=0; i--){
          if (i%2==0) cout << arr[i]<<' ';
      } 
      for (int i=0; i<n; i++){
          if (i%2==1) cout << arr[i]<<' ';
      } 
    }
	cout << endl;
}
