#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n),b;
	for(auto &i:a)cin >> i;
	b= a;
	sort(b.begin(),b.end());
	map<int,int> mp;
	for(int i = 0;i<n;i++)
	{
		mp[b[i]] = i%2;
	}
	int cnt = 0;
	for(int i =0;i<n;i++)
	{
		if(mp[a[i]]!=(i%2))cnt++;
	}
	cout << cnt/2 << endl;
}
