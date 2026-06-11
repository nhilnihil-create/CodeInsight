#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    string str;
	cin >> str;
 
	stack<int> s;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '0')
			s.push(0);
		else if (str[i] == '1' )
			s.push(1);
		else
		{
			if (s.empty() == false)
				s.pop();
		}
	}
 
	stack<int> temp;
	while (s.empty() == false)
	{
		temp.push(s.top());
		s.pop();
	}
 
	while (temp.empty() == false)
	{
		cout << temp.top() ;
		temp.pop();
	}
    return 0;
}