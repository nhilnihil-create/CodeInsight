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
typedef long long ll;
 
int main() {
	int n,m;
	cin >> n >> m;
	ll a[n],b[n],c[m],d[m];
	for (int i=0;i<n;i++) cin >> a[i] >> b[i];
	for (int i=0;i<m;i++) cin >> c[i] >> d[i];
	for (int i=0;i<n;i++) {
		int f=1;
		int e=abs(a[i]-c[0])+abs(b[i]-d[0]);
		for (int j=1;j<m;j++) {
			if (abs(a[i]-c[j])+abs(b[i]-d[j])<e) e=abs(a[i]-c[j])+abs(b[i]-d[j]),f=j+1;
		}
		cout << f << endl;
	}
}