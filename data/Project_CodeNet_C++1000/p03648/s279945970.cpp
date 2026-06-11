#include<iostream> 
#include<cstdio>
using namespace std;
long long k,i,x,y;
int main(){
	cin>>k;
	if(!k)cout<<"2\n"<<k/2<<' '<<k/2+1+(k&1)<<endl;
		else{
			puts("50");
			x=(k-1)/50;
			y=k-50*x;
			for(i=50+x;i>50+x-y;)cout<<i--<<' ';
			for(--i;i>=x;)cout<<i--<<' ';
		}
	return 0;
}