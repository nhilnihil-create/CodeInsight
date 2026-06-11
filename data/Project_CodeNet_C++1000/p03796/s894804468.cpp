#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;

int main(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); 

	long long  n; cin >> n; long long mult = 1;
	for (int i = 1; i <=n; i++){
		mult = (i% 1000000007 * mult% 1000000007)%1000000007;
		
	}
	cout << mult << endl;
	return 0;
}


