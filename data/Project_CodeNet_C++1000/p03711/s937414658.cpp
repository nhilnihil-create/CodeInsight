#include<iostream>
#include<set>
using namespace std;
int main()
{
	set<int> s1; 
	set<int> s2; 
	s1.insert(1);
	s1.insert(3);
	s1.insert(5);
	s1.insert(7);
	s1.insert(8);
	s1.insert(10);
	s1.insert(12);
	s2.insert(4);
	s2.insert(6);
	s2.insert(9);
	s2.insert(11);
	int x,y;
	cin>>x>>y;
	if(x==2||y==2)
	{
		cout<<"No"<<endl;
		exit(0);
	}
	else if(s1.find(x)!=s1.end()&&s1.find(y)!=s1.end())
	{
		cout<<"Yes"<<endl;
		exit(0);
	}
	else if(s2.find(x)!=s2.end()&&s2.find(y)!=s2.end())
	{
		cout<<"Yes"<<endl;
		exit(0);
	}
	cout<<"No"<<endl;
	return 0;
}