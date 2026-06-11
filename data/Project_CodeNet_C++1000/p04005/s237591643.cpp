#include <iostream>
using namespace std;

int main()
{
	long long A,B,C;
	cin>>A>>B>>C;
	long long maxx=0;
	int index=1;
	
	if(A>=B&&A>=C)
	{
		maxx=A;
		index=1;
	}
		
	if(B>=A&&B>=C)
	{
		maxx=B;
		index=2;
	}
		
	if(C>=A&&C>=B)
	{
		maxx=C;
		index=3;
	}
	
		
		
	if(maxx%2==0)
		cout<<"0"<<endl;
	if(maxx%2==1)
	{
		if(index==1)
			cout<<B*C<<endl;
		if(index==2)
			cout<<A*C<<endl;
		if(index==3)
			cout<<A*B<<endl;	
	}
}