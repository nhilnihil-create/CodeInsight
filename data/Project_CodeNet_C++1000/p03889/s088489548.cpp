#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[100005];cin>>a;
	int s=strlen(a);int sum=0;
	if(s%2!=0){
		cout<<"No";return 0;
	}
	for(int i=0;i<s;i++){
		if(a[i]=='p'&&a[s-i-1]=='q')sum++;
		if(a[i]=='q'&&a[s-i-1]=='p')sum++;
		if(a[i]=='d'&&a[s-i-1]=='b')sum++;
		if(a[i]=='b'&&a[s-i-1]=='d')sum++;
	}
	if(sum==s)cout<<"Yes";
	else cout<<"No";
	return 0;
} 