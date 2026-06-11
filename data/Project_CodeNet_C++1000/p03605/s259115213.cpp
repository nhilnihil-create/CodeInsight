#include<bits/stdc++.h>

using namespace std;

int main()
{ 
	int a;
	cin>>a;
	int b,c;
	b=a%10;
	a=a/10;
	c=a%10;
	if(b==9||c==9){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
		
}