#include <iostream>
#include <math.h>
#include <vector> 
#include <algorithm>


using namespace std;
int main()
{
	int N; 
	cin >> N;
	vector<long long> a(N);
	long long NC=0,x=0;
	for (int i = 0;i < N;i++) {
		cin >> a[i];
		NC += a[i];
	}
	long long ans = 2000000000;
		for (int j = 0;j < N;j++) {
			x += a[j];
			if (j + 1 < N)ans = min(ans, abs(NC - 2 * x));
		}
	cout << ans << endl;
}
