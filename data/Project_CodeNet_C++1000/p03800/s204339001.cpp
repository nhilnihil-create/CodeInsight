#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 100005;
int N;
string s;
char ans[MAX_N];

bool f()
{
	for (int i = 1; i < N-2; ++i)
	{
		if(s[i] == 'o' && ans[i] == 'S' && ans[i-1] == 'S') ans[i+1] = 'S';
		else if(s[i] == 'o' && ans[i] == 'S' && ans[i-1] == 'W') ans[i+1] = 'W';
		else if(s[i] == 'o' && ans[i] == 'W' && ans[i-1] == 'S') ans[i+1] = 'W';
		else if(s[i] == 'o' && ans[i] == 'W' && ans[i-1] == 'W') ans[i+1] = 'S';
		else if(s[i] == 'x' && ans[i] == 'S' && ans[i-1] == 'S') ans[i+1] = 'W';
		else if(s[i] == 'x' && ans[i] == 'S' && ans[i-1] == 'W') ans[i+1] = 'S';
		else if(s[i] == 'x' && ans[i] == 'W' && ans[i-1] == 'S') ans[i+1] = 'S';
		else if(s[i] == 'x' && ans[i] == 'W' && ans[i-1] == 'W') ans[i+1] = 'W';
	}
	/*
	rep(i,N)
	{
		cout << ans[i];
	}
	cout << endl;
	*/
	if ((ans[N-1] == 'S' && s[N-1] == 'o' && ans[0] == ans[N-2]) || (ans[N-1] == 'S' && s[N-1] == 'x' && ans[0] != ans[N-2]) || (ans[N-1] == 'W' && s[N-1] == 'o' && ans[0] != ans[N-2]) || (ans[N-1] == 'W' && s[N-1] == 'x' && ans[0] == ans[N-2]))
	{
		if ((ans[N-2] == 'S' && s[N-2] == 'o' && ans[N-1] == ans[N-3]) || (ans[N-2] == 'S' && s[N-2] == 'x' && ans[N-1] != ans[N-3]) || (ans[N-2] == 'W' && s[N-2] == 'o' && ans[N-1] != ans[N-3]) || (ans[N-2] == 'W' && s[N-2] == 'x' && ans[N-1] == ans[N-3]))
		{
			rep(i,N)
			{
				cout << ans[i];
			}
			cout << endl;
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> N;
	cin >> s;
	ans[0] = 'S';
	if (s[0] == 'o')
	{
		ans[1] = 'S'; ans[N-1] = 'S';
		if (f()) return 0;
		ans[1] = 'W'; ans[N-1] = 'W';
		if (f()) return 0;
	}
	else
	{
		ans[1] = 'S'; ans[N-1] = 'W';
		if (f()) return 0;
		ans[1] = 'W'; ans[N-1] = 'S';
		if (f()) return 0;
	}
	ans[0] = 'W';
	if (s[0] == 'o')
	{
		ans[1] = 'S'; ans[N-1] = 'W';
		if (f()) return 0;
		ans[1] = 'W'; ans[N-1] = 'S';
		if (f()) return 0;
	}
	else
	{
		ans[1] = 'S'; ans[N-1] = 'S';
		if (f()) return 0;
		ans[1] = 'W'; ans[N-1] = 'W';
		if (f()) return 0;
	}
	cout << "-1" << endl;
	return 0;
}