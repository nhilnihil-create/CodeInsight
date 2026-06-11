#include <bits/stdc++.h>
using namespace std;
int main()

{

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int x1,x2,x3,x4;
	cin>>x1>>x2>>x3>>x4;
	int area1=x1*x2;
	int area2=x3*x4;
	if(area1>=area2)
	{
		cout<< area1<<"\n";
	}
	else
	{
		cout<< area2<<"\n";
	}
}