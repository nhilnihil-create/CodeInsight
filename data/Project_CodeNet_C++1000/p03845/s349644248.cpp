#include <iostream>
using namespace std;
typedef long long ll;
const int N=110;

int n,m;
int t[N];
int sum;

int main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>t[i];
		sum+=t[i];
	}
	cin>>m;
	
	while(m--)
	{
		int i,v;
		cin>>i>>v;
		cout<<sum-t[i]+v<< endl;
	}
	
	return 0;
}