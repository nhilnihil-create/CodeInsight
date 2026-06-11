#include<iostream>
using namespace std;

string str1,str2,str3;
int main()
{
	cin>>str1>>str2>>str3;

	string ans ="";
	ans+=char(str1[0] - 'a' + 'A');
	ans+=char(str2[0]-'a' + 'A');
	ans+=char(str3[0] - 'a' + 'A');
	
	cout<<ans<<endl;

return 0;
}