#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,x;
	cin >> N >> x;
	if(N==2){
		if(x==2){
			cout << "Yes" << endl;
			for(int i=1;i<=3;i++)cout << i << endl;
			return 0;
		}
		cout << "No" << endl;
		return 0;
	}
	
	if(x==1 || x==2*N-1){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	
	N=2*N-1;
	vector<int> ans(N,0);
	
	if(x>2){
		ans[N/2]=x;
		ans[N/2-1]=x-1;
		ans[N/2+1]=x+1;
		ans[N/2+2]=x-2;
		
		int pos=0;
		for(int i=1;i<=N;i++){
			if(x-2<=i && i<=x+1)continue;
			while(ans[pos]!=0){
				pos++;
			}
			ans[pos]=i;
		}
	}
	else{
		ans[N/2]=x;
		ans[N/2-1]=x+1;
		ans[N/2+1]=x-1;
		ans[N/2+2]=x+2;
		
		int pos=0;
		for(int i=1;i<=N;i++){
			if(x-1<=i && i<=x+2)continue;
			while(ans[pos]!=0){
				pos++;
			}
			ans[pos]=i;
		}
	}
	for(int i=0;i<N;i++)cout << ans[i] << endl;
	return 0;	
}