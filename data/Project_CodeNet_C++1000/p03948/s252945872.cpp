#include <bits/stdc++.h>
using namespace std;




int main(){
	int N,T;
	cin>>N>>T;
	vector<int> A;
	for(int i=0;i<N;i++){
		int a;
		cin>>a;
		A.push_back(a);
	}
	
	vector<int> maxi(N);
	for(int i=N-1;i>=0;i--){
		if(i==N-1){
			maxi[i]=A[i];
		}
		else{
			maxi[i]=max(A[i],maxi[i+1]);
		}
	}
	
	int ans = 1;
	int dis = 0;
	
	for(int i=0;i<N-1;i++){
		int a = maxi[i+1]-A[i];
		if(dis==a)ans++;
		if(dis<a){
			ans=1;
			dis=a;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}
