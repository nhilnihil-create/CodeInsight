#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);

	int n, m,k=0; cin >> n >> m;

	if ((n+m)%3==0||n%3==0||m%3==0)cout << "Possible" << endl;
	else cout << "Impossible" << endl;

	return 0;
}

