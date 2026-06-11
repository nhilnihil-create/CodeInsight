#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	long long  a[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	if(a[2]%2==0){
		cout<<0<<endl;
	}else{
		cout<<a[0]*a[1]<<endl;
	}
	
	return 0;
}