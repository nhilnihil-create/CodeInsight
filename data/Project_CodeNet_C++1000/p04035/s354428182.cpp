#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll a[100000];
void output(int ind,int n)
{
	cout<<"Possible"<<endl;
	for(int i=1;i<ind;i++)
		cout<<i<<endl;
	for(int i=n-1;i>ind;i--)
		cout<<i<<endl;
	cout<<ind<<endl;
	return;
}
int main()
{
	int n;
	ll l;
	cin>>n>>l;
	for(int i=0;i<n;i++)
		cin>>a[i];
	bool f=false;
	for(int i=1;i<n;i++)
  {
		if(a[i]+a[i-1]>=l)
		{
			f=true;
			output(i,n);
			break;
		}
	}
	if(!f)
		cout<<"Impossible"<<endl;
	return 0;
}
