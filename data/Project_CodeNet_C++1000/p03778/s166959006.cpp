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
	int w,a,b;
	cin>>w>>a>>b;
	int a2 = a+w, b2 = b+w;
	int y = b-a2, y2 = a-b2;
	if(a<=b2 && a2>=b2)
		cout<<0<<endl;
	else if(a2>=b && a2<=b2)
		cout<<0<<endl;
	else 
	{
		int h = min(y,y2);
		if(h>0)
			cout<<h<<endl;
		else
			cout<<(y+y2-h)<<endl;
	}
	return 0;
}