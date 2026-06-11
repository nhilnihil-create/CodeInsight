#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[100001];
	cin>>a;
	for(int i=0;i<=strlen(a)-1;++i){
		if(a[i]=='9'){
			cout<<"Yes";return 0;
		}
	}cout<<"No";
}