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

	int A, B; cin >> A >> B;
	if ((A + B) < 24)
		cout << A + B << endl;
	else if ((A + B )>= 24)
		cout << A + B - 24 <<  endl;
	
	
	return 0;
}
