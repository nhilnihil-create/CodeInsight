#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main() {
	cin >> n;
  	int arr[n];
  	int sum = 0;
  	for (int i = 0; i < n; i++) {
    	cin >> arr[i];
      	sum += arr[i];
    }
  	int m1 = sum / n;
  	int m2 = sum / n + 1;
  	int c1 = 0;
  	int c2 = 0;
  	for (int i = 0; i < n; i++) {
    	c1 += (arr[i]-m1) * (arr[i]-m1);
     	c2 += (arr[i]-m2) * (arr[i]-m2);
    }
  	cout << min(c1, c2);
  
  
}