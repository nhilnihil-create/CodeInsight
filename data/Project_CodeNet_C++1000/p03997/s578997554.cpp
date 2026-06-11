#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;

int main()
{
	
	
	int a,b,h;
	cin>>a>>b>>h;
	
	int area;
	if(h%2==0)
	area=(a+b)*h/2;

	
	cout<<area<<endl;
	
	return 0;
}