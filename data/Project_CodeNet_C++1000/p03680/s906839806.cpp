#include <bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	int N;
	cin >> N;

	vector<int> a(N);
	REP(i, N){
		cin >> a[i];
	}

	int flashed = 1;
	int num = 0;

	REP(i, N){
		flashed = a[flashed - 1];
		num++;
		if(flashed == 2){
			cout << num << endl;
			return 0;
		}
	}

	cout << -1 << endl;
	return 0;
}