#include<iostream>

using namespace std;

int main()
{
	long long a,b,c;
	long long a_b,b_c,c_a; 
	
	cin>>a>>b>>c;
	if(a%2==0 || b%2==0 || c%2==0) cout<<0;
	else {
	
	long long res[3];
	res[0] = a*b;
	res[1] = b*c;
	res[2] = c*a;
	
	long long min = 1e18 + 1;
	for(int i=0;i<3;i++)
	{
		if(min > res[i])  min = res[i];
	}
	
	cout<<min;
	}
	return 0;
}