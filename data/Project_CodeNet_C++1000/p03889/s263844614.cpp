#include <iostream>
using namespace std;
int main()
{
	string a;
	int lena,sum=0;
	cin>>a;
	lena=a.size();
	for(int i=0;i<lena;++i)
	if((a[i]=='p'&&a[lena-i-1]=='q')||(a[i]=='d'&&a[lena-i-1]=='b'))
	++sum;
	if(lena%2==0)
	if(sum>=lena/2)
	cout<<"Yes"<<endl;
else cout<<"No"<<endl;
else if(sum>lena/2)
	cout<<"Yes"<<endl;
else cout<<"No"<<endl;
	return 0;
}