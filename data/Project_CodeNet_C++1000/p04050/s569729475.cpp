#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector <int> odds, evens;
	for (int i = 0; i < m; ++i)
	{
		int x;
		cin>>x;
		if(x%2)
			odds.push_back(x);
		else
			evens.push_back(x);
	}
	if(odds.size() > 2)
		cout<<"Impossible\n";
	else
	{
		vector <int> A, ans;
		if(odds.size() >= 1)
			A.push_back(odds[0]);
		for (int i = 0; i < evens.size(); ++i)
		{
			A.push_back(evens[i]);
		}
		if(odds.size() >= 2)
			A.push_back(odds[1]);
		if(A.size() == 1)
		{
			ans.push_back(A[0]-1);
			ans.push_back(1);
		}
		else
		{
			for (int i = 0; i < A.size(); ++i)
			{
				if(i == 0)
					ans.push_back(A[i] - 1);
				else if(i == A.size() - 1)
					ans.push_back(A[i] + 1);
				else
					ans.push_back(A[i]);
			}
		}
		vector <int> fans;
		for (int i = 0; i < ans.size(); ++i)
		{
			if(ans[i])
				fans.push_back(ans[i]);
		}
		for (int i = 0; i < A.size(); ++i)
		{
			cout<<A[i]<<" ";
		}
		cout<<"\n"<<fans.size()<<"\n";
		for (int i = 0; i < fans.size(); ++i)
		{
			cout<<fans[i]<<" ";
		}
	}
	return 0;
}