#include<bits/stdc++.h>
using namespace std;
string s,t;
int S[100007],T[100007];
int main()
{
	cin>>s>>t;
	int n=s.length(),m=t.length();
	for(int i=0;i<n;i++)S[i+1]=S[i]+(s[i]=='A'?1:2);
	for(int i=0;i<m;i++)T[i+1]=T[i]+(t[i]=='A'?1:2);
	int q;
	cin>>q;
	while(q--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		puts(((S[b]-S[a-1])-(T[d]-T[c-1]))%3==0?"YES":"NO");
	}
}