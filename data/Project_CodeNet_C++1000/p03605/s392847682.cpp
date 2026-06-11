#include<bits/stdc++.h>
using namespace std;//万能库
int main()
{
    int n,t;
    cin>>n;
    while(n>0){
    	t=n%10;
		if(t==9){
			cout<<"Yes"<<endl;
			return 0;
		} 
		n/=10;
	} 
	cout<<"No"<<endl;
    return 0;
}