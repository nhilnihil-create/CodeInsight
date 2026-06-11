#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int n,a;
	cin >> n >> a;
	vector<int> x(n);
	for(auto &i:x) cin >> i;
	vector<vector<vector<int64_t>>> dp(n+1,vector<vector<int64_t>>(n+1,vector<int64_t>(2501)));
	
	dp.at(0).at(0).at(0)=1;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<=2500; k++){
				if(dp.at(i).at(j).at(k)>=1) dp.at(i+1).at(j+1).at(k+x.at(i)) +=  dp.at(i).at(j).at(k);
				dp.at(i+1).at(j).at(k) += dp.at(i).at(j).at(k);
			}
		}
	}
	int64_t cnt=0;
	for(int j=1; j<n+1; j++){
		cnt += dp.at(n).at(j).at(j*a);
	}
	cout << cnt << endl;
}