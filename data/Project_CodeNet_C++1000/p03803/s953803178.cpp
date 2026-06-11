#include <iostream>
using namespace std ; 
int main()
{
	
	int A,B ;
	cin>>A>>B;
	if((A>B&&B!=1)||(A==1&&B!=1))
	cout<<"Alice "<<endl;
	else if (B>A||(B==1&&A!=1)&&A!=1)
	cout<<"Bob"<<endl;
	else if (A==B)
	cout<<"Draw"<<endl;
	
}