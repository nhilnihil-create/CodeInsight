#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[100004],b[100004];
	cin>>a;
	int k=strlen(a);
	k--;
	for(int i=0;i<=k;i++) 	b[i]=a[k-i];
		for(int i=0;i<=k;i++) {
		if(b[i]=='b') b[i]='d';
		else if(b[i]=='d') b[i]='b';
		else if(b[i]=='q') b[i]='p';
		else b[i]='q';
		if(a[i]!=b[i]) {
			cout<<"No"<<endl;
			return 0;
		}
		}
	cout<<"Yes"<<endl;
	return 0;
}