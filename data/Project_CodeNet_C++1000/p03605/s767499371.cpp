
#include<bits/stdc++.h>
using namespace std;
char a[3];
int main(){
	for(int i=0;i<2;i++){
		cin>>a[i];
		if(a[i]=='9'){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}