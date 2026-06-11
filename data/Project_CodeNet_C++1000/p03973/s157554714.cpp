#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;
 
int main(){
	long long n,i,q;
	long long cnt = 0;
	cin >> n;
	long long a[100000];
	for (long long i = 0; i < n; i++){
		cin >> a[i];
	}
	if (a[0]>1){
		cnt+=a[0]-1;
	}
	i = 1;
	q = 1;
	
	while (i<n){
		if (a[i] >(q+1)){
			cnt += ((a[i] - 1) / (q+1));
			a[i] = 1;
		}
		else if((q+1)==a[i]){
			q = a[i];
		}
		i++;
	}
	//cnt++;
	cout << cnt << endl;
	return 0;
}