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
	int n,a[1000] = {};
	cin >> n;
	for (int i=1;i<=n;i++) {
		int d=i;
		for (int j=2;j<=i;j++) {
	      	if (i%j==0) {
    	    	while( d%j == 0 ) {
        			d/=j;
        			a[j-1]++;
        		}
			}
		}
	}
	long long c=1;
	for (int i=0;i<1000;i++) c*=a[i]+1,c%=1000000007;
	cout << c; 
}