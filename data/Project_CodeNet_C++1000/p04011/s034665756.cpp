#include <iostream>
#include <vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
	int n,k,x,y,a=0,b=0,c=0;
	cin>>n>>k>>x>>y;
	if(n<=k)
	{
		c=n*x;
	}
	if(n>k)
	{
	  a=x*k;
	  b=(n-k)*y;
	  c=a+b;
    }
	cout<<c;
	return 0;
}