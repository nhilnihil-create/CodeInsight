#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long int cub[3];
	for(int i=0;i<3;i++)
		cin>>cub[i];
	if(cub[0]%2==0 || cub[1]%2==0 || cub[2]%2==0)
	{
		cout<<0<<endl;
		return 0;
	 } 
	else
	{
		sort(cub,cub+3);
		cout<<cub[0]*cub[1]<<endl;
		return 0;
	}
}