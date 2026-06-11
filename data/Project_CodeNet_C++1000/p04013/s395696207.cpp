#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,A;
	cin >> N >> A;
	vector<int> x(N);
	for(int i=0;i<N;i++)	cin >> x.at(i);
	
	int X=A;
	vector<int> y(N);
	for(int i=0;i<N;i++)	X=max(X,x.at(i));
	for(int i=0;i<N;i++)	y.at(i)=x.at(i)-A;
	
	vector<vector<long long>> dp(N+1,vector<long long>(2*N*X+1,0));
	dp.at(0).at(N*X)=1;
	for(int i=1;i<N+1;i++){
		for(int j=0;j<2*N*X+1;j++){
			dp.at(i).at(j)+=dp.at(i-1).at(j);
			if(j-y.at(i-1)>=0 && j-y.at(i-1)<=2*N*X){
				dp.at(i).at(j)+=dp.at(i-1).at(j-y.at(i-1));
			}
		}
	}
	cout << dp.at(N).at(N*X)-1 << endl;
	
	return 0;
}
