#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,A;
	cin >> N >> A;
	vector<int> x(N);
	for(int i=0;i<N;i++)	cin >> x.at(i);
	
	//i個め、これまでの合計、これまで何個選んできたか
	vector<vector<vector<long long>>> dp(N+1,vector<vector<long long>>(2501,vector<long long>(N+1,0)));
	dp.at(0).at(0).at(0)=1;
	for(int i=1;i<N+1;i++){
		for(int j=0;j<2501;j++){
			for(int k=0;k<N+1;k++){
				dp.at(i).at(j).at(k)+=dp.at(i-1).at(j).at(k);
				if(j-x.at(i-1)>=0 && k-1>=0){
					dp.at(i).at(j).at(k)+=dp.at(i-1).at(j-x.at(i-1)).at(k-1);
				}
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=N;i++){
		ans+=dp.at(N).at(A*i).at(i);
	}
	cout << ans << endl;
	
	return 0;
}
