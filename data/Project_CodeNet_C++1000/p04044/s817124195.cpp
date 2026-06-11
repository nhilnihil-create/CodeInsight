#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	int n,l;
	cin >> n >> l;
	vector<string> s(n);
	for(auto &i:s)cin >> i;
	sort(s.begin(),s.end());
	for(int i = 0;i<n;i++)cout<<s[i];
	cout<<endl;
}
