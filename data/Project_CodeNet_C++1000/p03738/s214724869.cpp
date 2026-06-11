#include<iostream>
using namespace std;

string str1,str2;
int main()
{
	cin>>str1>>str2;

	int len1 = str1.length();
	int len2 = str2.length();

	if (len1 < len2)cout<<"LESS"<<endl;
	else
	if (len1 > len2)cout<<"GREATER"<<endl;
	else
	{
		for (int i = 0 ; i < len1; i++)
		{
			if (str1[i] > str2[i]) {cout<<"GREATER"<<endl; return 0 ;}
			else
			if (str1[i] < str2[i])
			{
				cout<<"LESS"<<endl;
				return 0;
			}

		}
		cout<<"EQUAL"<<endl;
	}


return 0;
}
