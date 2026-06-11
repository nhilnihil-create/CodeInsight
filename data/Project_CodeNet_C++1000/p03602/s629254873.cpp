#include <iostream>
#include <vector>

using namespace std;

long long solve(const vector<vector<int>>& m){
	const int n = m.size();
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(m[i][k]+m[k][j] < m[i][j]) return -1;
			}
		}
	}
	long long res = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			bool require = true;
			for(int k=0;k<n;k++){
				if(i==k || j==k) continue;
				if(m[i][j] == m[i][k]+m[k][j]) require = false;
			}			
			if(require) res += m[i][j];
		}
	}
	return res;
}

int main(){
	int n;
	while(cin >> n){
		vector<vector<int>> A(n, vector<int>(n));
		for(auto& v : A){
			for(auto& t : v) cin >> t;
		}
		cout << solve(A) << endl;
	}
}