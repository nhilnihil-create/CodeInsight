#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
#define ll long long 
string s;
ll length,ans;
void dfs()
{
	length = s.length();
	ans = length; 
	if(length <= 1) return;
	for(int i = 0; i < length; i++)
	{
		if(i == length - 1) return;
		if(s[i] == 'S' && s[i+1] == 'T')
		{
			s.erase(i,2);
			i -= 2; 
			ans -= 2;
		} 
	}
	//dfs();
}
int main()
{
	cin >> s;
	dfs();
	printf("%d\n",ans);
	return 0;
} 