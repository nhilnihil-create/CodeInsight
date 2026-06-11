#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	for (int i=0;i<n;i++) cin >> a[i];
	sort (a,a+n);
	bool y=1;
	if (n%2==1) {
		for (int i=0;i<n;i++) {
			if (i%2) {
				if (a[i]!=i+1) y=0;	
			} else {
				if (a[i]!=i) y=0;
			} 
		}
		if (y==0) cout << 0;
		else {
			int b=1;
			for (int i=0;i<n/2;i++) {
				b=b*2%1000000007; 
			}
			cout << b;
		}
	} else {
		for (int i=0;i<n;i++) {
			if (i%2) {
				if (a[i]!=i) y=0;	
			} else {
				if (a[i]!=i+1) y=0;
			} 
		}
		if (y==0) cout << 0;
		else {
			int b=1;
			for (int i=0;i<n/2;i++) {
				b=b*2%1000000007; 
			}
			cout << b;
		}
	}
	
}