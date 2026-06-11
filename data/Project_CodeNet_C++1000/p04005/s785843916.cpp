#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long A,B,C,x,y,z;
int main(int argc, char** argv) 
{
	cin>>A>>B>>C;
	if(A%2==0||B%2==0||C%2==0) cout<<0<<endl;
	else
	{
		x=A*B,y=B*C,z=C*A;
		if(x>y) x=y;
		if(x>z) x=z; 
		cout<<x<<endl;
	}
	return 0;
}