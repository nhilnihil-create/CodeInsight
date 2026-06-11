#include<bits/stdc++.h>
using namespace std;
int main() {
	string a;
	cin>>a;
	string b=a;
	reverse(a.begin(),a.end());
	int len=a.size();
	for(int i=1;i<=len;i++) {
		if(b[i]=='b') {
			b[i]='d';
		}
		else if(b[i]=='d') {
			b[i]='b';
		}
		else if(b[i]=='q') {
			b[i]='p';
		}
		else if(b[i]=='p') {
			b[i]='q';
		}
	}
	for(int i=1;i<=len;i++) {
		if(b[i]==a[i])
		{
			continue;
		}
		else
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}