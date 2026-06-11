#include<iostream>
#include<algorithm> 
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* p=new int [2*n];  
	for (int i=0;i<2*n;i++)
	{
		cin >> p[i];
	}
	sort(p,p+2*n);
	int s=0;
	for(int i=0;i<2*n;i+=2)
	{
		s+=p[i];
	}
	cout << s << endl;
	return 0;
} 