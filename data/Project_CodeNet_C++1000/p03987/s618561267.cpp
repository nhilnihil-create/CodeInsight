#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<set>
#define mod  998244353
#define int long long int
int32_t main()
{
	int n;
	cin>>n;
	int j,arr[n+1];
	for(j=1;j<=n;j++)
	    cin>>arr[j];
	int answer=0;
	int position[n+1];
	for(j=1;j<=n;j++)
	{
		position[arr[j]]=j;
	}
	set<int> s;
	s.insert(0);
	s.insert(n+1);
	for(j=1;j<=n;j++)
	{
		int x=position[j];
		auto it=s.upper_bound(x);
		int right=*it;
		right--;
		it--;
		int left=*it;
		left++;
		answer+=j*(x-left+1)*(right-x+1);
		s.insert(x);

	}
	cout<<answer<<endl;
}
