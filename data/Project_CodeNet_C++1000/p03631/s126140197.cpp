#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char c[1001];
int main()
{
    cin>>c[0]>>c[1]>>c[2];
    if(c[0]-'0'==c[2]-'0')
	{
		cout<<"Yes"<<endl;
	}
    else 
	{
		cout<<"No"<<endl;	
	}
	cout<<endl;
    return 0;
}