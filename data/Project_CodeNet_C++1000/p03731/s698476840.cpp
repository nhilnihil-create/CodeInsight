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
	int N,T;
	cin >> N >> T;
	int t[N],a=T;
	for (int i=0;i<N;i++) cin >> t[i];
	for (int i=0;i<N-1;i++) {
		a+=min(T,t[i+1]-t[i]);
	}
	cout << a;
}