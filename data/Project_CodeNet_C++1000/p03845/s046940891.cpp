#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; 
	cin >> N;
	int T[N];
	for (int i=0; i<N; i++) cin >> T[i];
	int M;
	cin >> M;
	vector <vector <int>> drink(M, vector <int> (2));
	for (int i=0; i<M; i++){
	    cin >> drink[i][0] >> drink[i][1];
	}
	int total;
	for (int i=0; i<N; i++) total+=T[i];
	int ans;
	for (int i=0; i<M; i++){
	    ans=total-T[drink[i][0]-1]+drink[i][1];
	    cout << ans << endl;
	}
}
