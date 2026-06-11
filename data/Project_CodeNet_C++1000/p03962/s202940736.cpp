#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	vector<int> a(3);
	for(int i = 0;i<3;i++)cin >> a[i];
	sort(a.begin(),a.end());
	cout<<3-(a[0]==a[1])-(a[1]==a[2])<<endl;
}
