#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	n*=2;
	vector<int> arr;
	for(int i =0;i<n;i++)
	{
		int a;
		cin>>a;
		arr.push_back(a);
	}
	sort(arr.begin(),arr.end());
	int cnt = 0;
	for(int i =0; i < arr.size();i+=2)
		cnt += min(arr[i],arr[i+1]);
	
	cout<<cnt<<endl;
	return 0;
}