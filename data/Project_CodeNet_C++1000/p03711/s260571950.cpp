#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int x,y;
	cin>>x>>y;
	set<int> s1;
	s1.insert(1);
	s1.insert(3);
	s1.insert(5);
	s1.insert(7);
	s1.insert(8);
	s1.insert(10);
	s1.insert(12);
	if(s1.count(x)==1 && s1.count(y)==1)
		cout<<"Yes"<<endl;
	else
	{
		if(x==2 && y==2)
			cout<<"Yes"<<endl;
		else if(s1.count(x)==0 && s1.count(y)==0 && x!=2 && y!=2)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}