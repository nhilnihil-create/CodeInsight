#include "bits/stdc++.h"

using namespace std;

const int INF = numeric_limits<int>::max() / 2;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H,W,h,w;cin>>H>>W>>h>>w;
	if(H%h==0 && W%w==0){
		cout<<"No"<<endl;
		return 0;
	}
	vector<vector<int>> res(H,vector<int>(W,1));
	if(W%w!=0){
		vector<int> sum(W+1,0);
		for(int i=w;i<=W;i+=w){
			sum[i]=sum[i-w]-1;
		}
		for(int i=W;i>0;i--){
			if(sum[i]!=0) continue;
			sum[i]=1;
			for(int j=i-w;j>0;j-=w){
				sum[j]=sum[j+w]+1;
			}
		}
		for(int i=0;i<W;i++){
			res[0][i]=sum[i+1]-sum[i];
		}
		for(int i=1;i<H;i++){
			for(int j=0;j<W;j++){
				res[i][j]=res[0][j];
			}
		}
	}
	else{
		vector<int> sum(H+1,0);
		for(int i=h;i<=H;i+=h){
			sum[i]=sum[i-h]-1;
		}
		for(int i=H;i>0;i--){
			if(sum[i]!=0) continue;
			sum[i]=1;
			for(int j=i-h;j>0;j-=h){
				sum[j]=sum[j+h]+1;
			}
		}
		for(int i=0;i<H;i++){
			res[i][0]=sum[i+1]-sum[i];
		}
		for(int i=0;i<H;i++){
			for(int j=1;j<W;j++){
				res[i][j]=res[i][0];
			}
		}
	}
  cout<<"Yes"<<endl;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(j==0) cout<<res[i][j];
			else cout<<" "<<res[i][j];
		}
		cout<<endl;
	}
}
