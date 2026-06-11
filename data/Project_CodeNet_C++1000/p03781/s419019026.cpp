#include <iostream>

using namespace std;

int X;

int main(void)
{
	cin >> X;
	
	int ans, dist = 0;
	for(ans = 1; ; ans++){
		dist += ans;
		if(dist >= X) break;
	}
	
	cout << ans << endl;
	return 0;
}