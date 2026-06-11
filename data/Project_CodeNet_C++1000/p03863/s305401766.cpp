#include <bits/stdc++.h>
using namespace std;
char a[100005];
int length;
int main() {
	cin>>a;
	length=strlen(a);
	if(a[0]==a[length-1]){
		if(length%2==1) cout<<"Second";
		else cout<<"First";
	}
	else{
		if(length%2==1) cout<<"First";
		else cout<<"Second";
	}
	return 0;
}