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
	int a,b,c;
	cin >> a >> b >> c;
	if (a>b && a>c) {
		if (a==b+c) cout << "Yes\n";
		else cout << "No\n";
	} else if (b>a && b>c){
		if (b==a+c) cout << "Yes\n";
		else cout << "No\n";
	} else {
		if (c==a+b) cout << "Yes\n";
		else cout << "No\n";
	}
}