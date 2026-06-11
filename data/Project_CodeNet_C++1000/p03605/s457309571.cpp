#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char a[10];
	cin>>a;
	for(int i=0;i<strlen(a);i++){
		if(a[i]=='9'){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
}