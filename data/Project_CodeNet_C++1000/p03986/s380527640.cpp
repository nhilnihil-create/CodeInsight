#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> q;
string t;

int main()
{
	cin >> t;
	int l = t.size();
	for (int i = 0; i < l; i++)
	{
		if (q.empty() == true)
		{
			q.push(t[i]);
			continue;
		}
		if (q.top() == 'S' && t[i] == 'T')
		{
			q.pop();
			continue;
		}
		q.push(t[i]);
	}
	cout << q.size() << endl;

	return 0;
}
