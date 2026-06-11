#include <bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;

	vector<int> a(M), b(M);
	REP(i, M){
		cin >> a[i] >> b[i];
	}

	vector<int> number_of_road(N);
	REP(i, M){
		number_of_road[a[i] - 1]++;
		number_of_road[b[i] - 1]++;
	}
	REP(i, N){
		cout << number_of_road[i] << endl;
	}

}
