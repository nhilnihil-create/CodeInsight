#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int l,r;
	string s;
	cin >> s;
	int n = s.size();
	for(int i = 0;i<n;i++) { if(s[i]=='A') { l=i;break; } }
	for(int i = n-1;i>=0;i--) { if(s[i]=='Z') { r=i;break; } }
	cout<<r-l+1<<endl;
}
