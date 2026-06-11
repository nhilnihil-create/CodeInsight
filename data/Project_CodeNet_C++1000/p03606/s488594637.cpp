#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{	
	int n,a,b,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		sum+=b-a+1;
	}
	cout<<sum<<endl;
	return 0;
}