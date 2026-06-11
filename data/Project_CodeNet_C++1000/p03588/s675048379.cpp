#include <iostream>
#include <string>
#include <algorithm>
#include <map>


using namespace std;

int main(void) {

	int N, A[100010], B[100010], tmp = 0, ans;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
		if (tmp < A[i]) {
			tmp = A[i];
			ans = A[i] + B[i];
			//if (tmp == N) {
			//	break;
			//}
		}
	}
	   	  
	cout << ans;

	return 0;
}

