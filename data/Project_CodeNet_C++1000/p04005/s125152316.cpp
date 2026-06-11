#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	long long a[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	if(a[2]%2==0){
		cout<<"0"<<endl;
	}
	else{
		long long s=a[1]*a[0];
		cout<<s<<endl;
	}
	return 0;
}