#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	(s.find('9')>=0&&s.find('9')<s.size())?printf("Yes\n"):printf("No\n");
	return 0;
}