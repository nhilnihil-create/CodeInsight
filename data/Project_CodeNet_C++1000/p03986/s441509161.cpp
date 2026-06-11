#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
#define N 1000+20
#define ll long long
stack<char> st;
int main()
{
	string s;
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		if (!st.empty()&&st.top() == 'S' && s[i] == 'T')
		{
			st.pop();
			continue;
		}
		st.push(s[i]);
	}
	cout << st.size() << endl;
}