#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{	
	int a,b,c,d,ans=0;
	cin>>a>>b>>c>>d;
	for(int i=0;i<=100;i++)
	{
		if(a<i&&i<=b&&c<i&&i<=d)ans++;
	}
	cout<<ans<<endl;
}