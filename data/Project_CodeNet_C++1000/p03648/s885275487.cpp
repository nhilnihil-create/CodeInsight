#include<iostream>
using namespace std;
long k;
main()
{
	cin>>k;
	cout<<50<<endl;
	for(int i=0;i<50;i++)cout<<k/50+49-k%50+(i<k%50)*50<<endl;
}
