#include <bits/stdc++.h>
     
using namespace std;

int psum1[100001];
int psum2[100001];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s,t;
	int a,b,c,d;

	cin >> s;
	cin >> t;
	
	psum1[0] = 0;
	psum2[0] = 0;

	for(int i=1;i<=s.length();i++)
	{
		psum1[i] = psum1[i-1];
		if(s[i-1]=='A')
		{
			psum1[i] += 1;
		}
		else
		{
			psum1[i] += 2;
		}
	}

	for(int i=1;i<=t.length();i++)
	{
		psum2[i] = psum2[i-1];
		if(t[i-1]=='A')
		{
			psum2[i] += 1;
		}
		else
		{
			psum2[i] += 2;
		}
	}

	int q;

	cin >> q;

	for(int i=0;i<q;i++)
	{
		cin >> a >> b >> c >> d;
		int x = psum1[b] - psum1[a-1];
		int y = psum2[d] - psum2[c-1];
		x%=3;
		y%=3;
		if(x==y)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}

	return 0;
}
