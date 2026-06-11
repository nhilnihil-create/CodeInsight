#include<iostream>
using namespace std;
int main(){
	int n,a1=0,a2=0,a4=0;
	cin>>n;
	while(n--){
		int temp;
		cin>>temp;
		if(temp%4==0) a4++;
		else if(temp%2==0) a2++;
		else a1++;
	}
	if(a2==0){
		if(a4+1>=a1) cout<<"Yes";
		else cout<<"No";
	}else {
		if(a4>=a1) cout<<"Yes";
		else cout<<"No";
	}
	return 0;
}
