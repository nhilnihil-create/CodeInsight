#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <climits>

using namespace std;

int calc(long long  num) {

	int keta=0;

	while (num>0) {		
		num = num / 10;
		keta++;
	}

	return keta;
}


int main(){
	long long n;
	cin >> n;

	int ans = 100;

	long long i = 1;
	while ( i*i <= n) {
		if (n % i == 0) {
			long long b = n / i;            
			
			int c=max(calc(i), calc(b));
			
			if (ans > c)ans = c;
			if (ans < c)break;
		}
		i++;
	}

	cout<<ans<<endl;

	return 0;
}