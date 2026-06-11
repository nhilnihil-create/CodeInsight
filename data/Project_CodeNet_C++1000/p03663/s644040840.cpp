#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool In(){
	char z;
	cin>>z;
	if(z=='N')return false;
	return true;
}
int main(){
	long long t=1000000000;
	while(true){
		//rrrrr
		cout<<"? "<<t<<"\n"<<flush;
		if(In()){
			if(t==1000000000){
				long long x=500000000;
				while(true){
					cout<<"? "<<x<<"\n"<<flush;
					if(!In()){
						break;
					}
					x/=10;
					if(x==0){
						cout<<"! "<<1<<"\n"<<flush;
						return 0;
					}
				}
				cout<<"! "<<x*2<<"\n"<<flush;
				return 0;
			}
			break;
		}
		t/=10;
	}
	long long left=t,right=t*10;
	long long mid,ans=114514114514114514;
	while(left<right){
		mid=(left+right)/2;
		//rrrrr
		cout<<"? "<<mid*10<<"\n"<<flush;
		if(!In()){
			left=mid+1;
		}
		else{
			right=mid;
			ans=min(ans,mid);
		}
	}
	//rrrrr
	cout<<"! "<<ans<<"\n"<<flush;
	return 0;
}
