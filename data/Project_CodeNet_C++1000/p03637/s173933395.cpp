#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin>>n;
	int x,y,z;
	x=y=z=0;
	for(int i = 0; i < n; i++)
	{
		int m;
		cin>>m;
		if(m%4==0)
		x++;
		else if(m%2==0)
		y++;
		else
		z++;
	}
	if(z<=x||(z==x+1&&y==0))
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
	return 0; 
}