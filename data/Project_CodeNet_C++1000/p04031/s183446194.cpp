#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	int n,d;
	long b=1000000000;
	vector <int> ve;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>d;
		ve.push_back(d);
	}
    for(int i=-100;i<101;i++)
    {
    	long a=0;
    	for(int j=0;j<n;j++)
    	{
    		a+=((i-ve[j])*(i-ve[j]));
		}
		b=min(b,a);
	}
	cout<<b;
	return 0;
}