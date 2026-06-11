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
	int n;
	cin>>n;
	string s;
	cin>>s;
	int x = 0;
	int y1 = count(s.begin(),s.end(),'(')-count(s.begin(), s.end(),')');
	if(y1!=0)
	for(int i = 0;i<abs(y1); i++)
			if(y1>0)
				s += ')';
			else
				s = '('+s;
	int a[s.length()];
	for(int i = 0;i <s.length(); i++)
	{
		if(s[i]=='(')
			x++;
		else
			x--;
		a[i] = x;
	}
	int y = *min_element(a,a+s.length());
	// int r = a[n-1];
	if(y<0)
		for(int i = 0; i<abs(y); i++)
			s = '('+s+')';
	cout<<s<<endl;
	return 0;
}