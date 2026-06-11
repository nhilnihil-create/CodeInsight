#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

long long A,B,C=0;

int main()
{
	ios::sync_with_stdio(false);
	
	cin>>A>>B>>C;
	
	if(A%2==0||B%2==0||C%2==0)
	{
		cout<<"0"<<endl;
	}
	else{
		long long mn=A*B;//最小值
		if(B*C<mn){
			mn=B*C;
		} 
		if(A*C<mn){
			mn=A*C;
		}
		 
		cout<<mn<<endl;
		
	}
	
	return 0;
	
}