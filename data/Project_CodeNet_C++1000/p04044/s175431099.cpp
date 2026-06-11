#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s[N];
int n,l;
int main(){
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++)
		cin>>s[i];
	sort(s+1,s+1+n);
	for(int i=1;i<=n;i++)
		cout<<s[i];
	return 0;
}