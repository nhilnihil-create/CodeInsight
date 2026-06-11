#include<iostream>
using namespace std;
int main(void){
	long long x;
	cin>>x;
	long long div,mod;
	div = x / 11;
	mod = x % 11;
	long long tmp = div*2;
	if(mod == 0)cout<<tmp<<endl;
	else if(mod <= 6)cout<<(long long)(tmp+1)<<endl;
	else cout<<(long long)(tmp+2)<<endl;
	return 0;
}