#include <bits/stdc++.h>
using namespace std;

int main(){
	long long q,h,s,d,n;
	cin >> q >> h >> s >> d >> n;
	
	int twoliter = min(min(8*q,4*h),min(2*s,d));
	int liter = min(min(4*q,2*h),s);
	if ( n == 1) cout << liter;
	else {
		if (liter*2 < twoliter){
			cout << n * liter;
		}
		else{
			if (n%2==1){
				cout << n/2*twoliter + liter;
			}
			else cout << n/2*twoliter;
		}
	}
 }
