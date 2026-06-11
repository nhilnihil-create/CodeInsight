#include <iostream>
using namespace std;
int a[100005];
int main()
{
	int n,t;
	cin >> n >> t;
	for(int i = 0;i < n;i++)
	cin >> a[i];
	int min1 = 1000000007,maxc = 0;
	for(int i = 0;i < n;i++)
	{
		 min1 = min(min1 , a[i]);
		 maxc = max(maxc , a[i] - min1);
	}
	int ans = 0;
	min1 = 1000000007; 
	for(int i = 0;i < n;i++)
	{
		min1 = min(min1 , a[i]);
		if(a[i] - min1 == maxc)
		ans++;
	 } 
	 cout << ans << endl;
	return 0;
}