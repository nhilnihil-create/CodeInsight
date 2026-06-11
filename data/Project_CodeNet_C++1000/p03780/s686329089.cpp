#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,K;
	cin >> N >> K;
	vector<int> a(N);
	for(auto &i:a)cin >> i;
	
	vector<int> b;
	for(auto i:a)if(i<K)b.push_back(i);
	int M=b.size();
	sort(b.begin(),b.end());
	
	if(M<=1){
		cout << M << endl;
		return 0;
	}
	
	int ok=-1,ng=M;
	while(abs(ok-ng)>1){
		int mid=(ok+ng)/2;
		bool dp[M+1][5000];
		for(int i=0;i<M+1;i++)for(int j=0;j<5000;j++)dp[i][j]=false;
		dp[0][0]=true;
		for(int i=0;i<M;i++){
			if(i==mid){
				for(int j=0;j<5000;j++){
					dp[i+1][j]|=dp[i][j];
				}
			}else{
				for(int j=0;j<5000;j++){
					dp[i+1][j]|=dp[i][j];
					if(j>=b[i])dp[i+1][j]|=dp[i][j-b[i]];
				}
			}
		}
		bool flag=false;
		for(int j=K-b[mid];j<K;j++)flag|=dp[M][j];
		if(!flag)ok=mid;
		else ng=mid;
	}
	cout << ok+1 << endl;
	return 0;
}