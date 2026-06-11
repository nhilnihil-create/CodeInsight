#include <bits/stdc++.h>
using namespace std;

int X[200001];
int Y[100001];

int main(){
	int N,M;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		int x;
		cin>>x;
		X[x]++;
		Y[x%M]++;
	}
	int res = 0;
	res += Y[0]/2;
	//for(int i=0;i<M;i++){cout<<Y[i]<<endl;}
	for(int i=1;i<M/2+1;i++){
		//cout<<res<<endl;
		if(i == M-i){
			res += Y[i]/2;
		}
		else{
			res += min(Y[i],Y[M-i]);
			//cout<<i<<","<<res<<endl;
			int ind;
			if(Y[i] < Y[M-i]){
				ind = M-i;
			}
			else if(Y[M-i] < Y[i]){
				ind = i;
			}
			else{
				continue;
			}
			int cnt = 0;
			for(int j=ind;j<100001;j+=M){
				cnt += X[j]/2;
			}
			res += min(cnt,(max(Y[i],Y[M-i])-min(Y[i],Y[M-i]))/2);
		}
		
		//cout<<res<<endl;
	}
	cout<<res<<endl;
}