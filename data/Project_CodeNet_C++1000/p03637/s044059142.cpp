#include<cstdio>
#include<iostream>
#include<numeric> //求和 
#include<string>
#include<algorithm>
const int maxn=50001;
using namespace std;
int main(void)
{
	int n,temp,a=0,b=0,c=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		if(temp%2==0){
			if(temp%4==0) a++;
			else b++;
		}else{
			c++;
		}
	}
	//cout<<a<<" "<<b<<" "<<c<<endl;
	if(a>=c || (b==0 && a+1==c)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}