#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	int a,b;
	cin>>a>>b;
	if(a==b)cout<<"Draw"<<endl;
	else if(a>b&&b!=1)cout<<"Alice"<<endl;
	else if(a<b&&a!=1)cout<<"Bob"<<endl;
	else if(a==1)cout<<"Alice"<<endl;
	else if(b==1)cout<<"Bob"<<endl;
	return 0;
}