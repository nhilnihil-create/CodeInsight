#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main(void){
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++)cin >> a[i];
	sort(a, a+n);
	int i = a[0]+1;
	if(n%2 == a[0]){
		cout << 0 << endl;
		return 0;
	}
	for( ; i<n; i+=2){
		if(a[i]/2==(i + (n%2? 0 : 2))/2){
			cout << 0 << endl;
			return 0;
		}
	}
	long long r = 1;
	long long m = 1e9 +7;
	for(int i=0; i<n/2; i++){
		r = (r%m * 2)%m;
	}

	cout << r << endl;
}