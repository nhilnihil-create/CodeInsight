#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string a,b;
    cin>>a;
    b=a;
    reverse(a.begin(),a.end());
    for(int i=0;i<a.size();i++)
		switch(a[i])
		{
			case 'b':a[i]='d';break;
			case 'd':a[i]='b';break;
			case 'p':a[i]='q';break;
			case 'q':a[i]='p';break;
		} 
    if(a==b)
		cout<<"Yes"<<endl;
    else
		cout<<"No"<<endl;
}