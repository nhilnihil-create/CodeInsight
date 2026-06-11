#include<bits/stdc++.h>
using namespace std;
inline bool cmp(string a,string b){
	return a<b;
}
int main()
{
	std::ios::sync_with_stdio(false);
	string b[111];
	int n,l;
	cin>>n>>l;
	for(int i=1;i<=n;i++)
	cin>>b[i];
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++)
	cout<<b[i];
	cout<<endl;
	return 0;
}