#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll n,x;
	cin >> n >>x ;
	if(2<=x&&x<=2*n-2)
	{
		cout << "Yes"<<endl;
		vector<int> ans(2*n-1);
		for(int i = 1;i<=ans.size();i++)
			ans[i-1] = i;
		for(int i = 0;i<ans.size();i++)
		{
			int buff = -(n) + x + ans.size();
			buff %= ans.size();
			buff = (i+buff)%ans.size();
			cout << ans[buff]<<endl;
		}
	}
	else cout << "No"<<endl;
}
