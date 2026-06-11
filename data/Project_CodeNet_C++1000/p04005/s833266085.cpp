#include <iostream>
#include <algorithm> 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	long long a[4];
	bool j[4];
	for(int i=0;i<3;i++)	
	{
		cin>>a[i];
		j[i]=a[i]%2;
	}
	if(j[0]&&j[1]&&j[2])
	{
		sort(a,a+3);
		cout<<a[0]*a[1];
		return 0; 
	}
	cout<<0;
	return 0;
}