#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n,L;cin>>n>>L;
	int a[n]; for(int i = 0; i < n; i++) cin>>a[i];
	
	bool flag = false;
	int left,right;
	for(int i = 0; i < n-1; i++){
		if(a[i]+a[i+1] >= L){
			//cout<<"i = "<<i<<", a[i] = "<<a[i]<<", L = "<<L<<endl;
			flag = true;
			left = i;
			right = i+1;
		}
	}
	if(flag == false){
		cout<<"Impossible"<<endl;
		return 0;
	}
	else{
		//cout<<"left = "<<left<<", right = "<<right<<endl;
		cout<<"Possible"<<endl;
		if(left >= 1){
			for(int i = 1; i <= left; i++){
				cout<<i<<endl;
			}
		}
		if(right < n-1){
			for(int i = n-1; i > right; i--){
				cout<<i<<endl;
			}
		}
		cout<<right<<endl;
	}
	return 0;
}

