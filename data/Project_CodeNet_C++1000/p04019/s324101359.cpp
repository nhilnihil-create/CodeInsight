#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	map<char,int> m;
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		m[str[i]]++;//统计每个方向走的步数
	}
	if(((m['N']+m['S']!=0)&&(m['N']*m['S']==0))||((m['E']+m['W']!=0)&&(m['E']*m['W']==0)))//只有其中一个
	{
		cout<<"No"<<endl;
	}
	else
	{
		cout<<"Yes"<<endl;
	}
	return 0;
}