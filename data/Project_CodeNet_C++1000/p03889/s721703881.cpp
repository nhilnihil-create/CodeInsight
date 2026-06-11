/**/
#include<bits/stdc++.h>
using namespace std;
char a[100001];
int main(){
	ios::sync_with_stdio(false);
	gets(a);
	int len=strlen(a);
	for(int i=0;i<len;i++){
		if(!(a[i]=='p'&&a[len-i-1]=='q'||a[i]=='q'&&a[len-i-1]=='p'||a[i]=='b'&&a[len-i-1]=='d'||a[i]=='d'&&a[len-i-1]=='b')){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}
