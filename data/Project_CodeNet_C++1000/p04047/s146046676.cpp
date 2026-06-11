#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	cin>>n;
	int s[2*n],ans=0;
	for(int i=0;i<2*n;i++)
	cin>>s[i];
	sort(s,s+2*n);
	for(int i=0;i<2*n;i=i+2)
	ans+=s[i];
	cout<<ans;
return 0;	
}