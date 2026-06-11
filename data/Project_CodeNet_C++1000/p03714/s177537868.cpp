#include <iostream>
#include<algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int N;
long long int a[300005];
long long int L[300005], R[300005];

priority_queue<long long int, vector<long long int>, greater<long long int > > PQ;
priority_queue<long long int> PQ2;

long long int max_val, min_val;

int main(void) {

	cin >> N;

	long long int tmp;
	for (int i = 1; i <= 3*N; i++) {
		cin >> tmp; a[i] = tmp;
	}

	//===========L==============
	for (int i = 1; i <= N; i++) {
		L[N] += a[i]; PQ.push(a[i]);
	}

	
	for (int K = N + 1; K <= 2 * N; K++) {
		min_val = PQ.top(); //cout << min_val << endl;
		//cout << a[K] << "   " << min_val << endl;
		if (a[K] <= min_val) { L[K] = L[K-1]; }
		else { L[K] = L[K - 1] - min_val + a[K]; PQ.pop(); PQ.push(a[K]);}
	}
	

	//===========R===============
	for (int i = 3 * N; i >= 2 * N+1; i--) {
		R[2 * N+1] += a[i];  PQ2.push(a[i]);
	}

	
	for (int K = 2 * N; K >= N + 1; K--) {
		max_val = PQ2.top();  //cout << "max_val= " << max_val << endl;
		if (a[K] >= max_val) { R[K] = R[K + 1]; }
		else { R[K] = R[K + 1] - max_val + a[K]; PQ2.pop(); PQ2.push(a[K]); }
	}


//===========================
	
	

	
	/*for (int K = N; K <= 2 * N; K++) {
		cout << "L[" << K << "]= " <<L[K] << endl;
	}
	for (int K = N+1; K <= 2 * N+1; K++) {
		cout << "R[" << K << "]= " << R[K] << endl;
	}*/

	long long int ans = -1000000000000005;
	for (int K = N; K <= 2 * N; K++) {
		ans = max(ans, L[K] - R[K + 1]);
		//cout << ans << endl;
	}
	
	cout << ans << endl;
	//system("pause");
	return 0;
}