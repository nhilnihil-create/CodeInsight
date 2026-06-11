#include <iostream>
#include <cstdio>
using namespace std;
int a,b;
int main()
{
	scanf("%d%d",&a,&b);
	if(a<=0&&b>=0) printf("Zero");
	else 
	{
		if(a>0) printf("Positive");
		else if((b-a+1)%2==0) printf("Positive");
		else printf("Negative");	
	}
	return 0;
}