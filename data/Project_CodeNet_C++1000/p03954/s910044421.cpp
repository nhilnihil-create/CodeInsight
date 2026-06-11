#include<iostream>
using namespace std;
typedef long long int ll;
static const int MAX_N = 100000;
static const int MAX_A = 2 * MAX_N - 1;

int N, a[2 * MAX_N - 1];

bool def(bool b[]){
	int s = 0, t = 0;
	while(N - s - 1 > 0 && b[N - s - 1] != b[N - s - 2]) s++;
	while(t + N - 1 < 2 * N - 1 && b[N + t - 1] != b[N + t]) t++;
	if(min(s, t) >= N - 1) return ((N % 2) ? b[N - 1] : !b[N - 1]);
	else if(t < s) return b[t + N - 1];
	else return b[N - s - 1];
}

int main(){
	cin >> N;
	for(int i = 0; i < 2 * N - 1; i++) cin >> a[i];
	
	int lb = -1, ub = MAX_A + 1;
	while(ub - lb > 1){
		int mid = lb + (ub - lb) / 2;
		bool b[2 * MAX_N - 1];
		for(int i = 0; i < 2 * N - 1; i++){
			if(a[i] >= mid) b[i] = true;
			else b[i] = false;
		}
		if(def(b)) lb = mid;
		else ub = mid;
	}
	cout << lb << endl;
	return 0;
}
