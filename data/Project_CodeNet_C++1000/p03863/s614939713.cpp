#include<bits/stdc++.h>
using namespace std;
int main() {
	char a[1000001];
	scanf("%s",a);
	if(a[0]==a[strlen(a)-1]) {
		if((strlen(a))%2==1) cout<<"Second"<<endl;
		else cout<<"First"<<endl;
	} else {
		if((strlen(a))%2==1) cout<<"First"<<endl;
		else cout<<"Second"<<endl;
	}
	return 0;
}