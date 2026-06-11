#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	stack<char> x;
	string a;
	char ex='T';
	cin >> a;
	for(int i=0;i<a.length();i++)
	{
		x.push(a[i]);
		if (ex == 'S' && x.top() == 'T')
		{
			x.pop();
			x.pop();
		}
		if (x.size() == 0)ex = 'T';
		else
			ex = x.top();
	} 
	cout << x.size () << endl;
	return 0;
}
