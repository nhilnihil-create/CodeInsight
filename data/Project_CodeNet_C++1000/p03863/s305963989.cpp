#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin>>a;
	if(a[0]==a[a.length()-1]&&a.length()%2==1){
		cout<<"Second";
		return 0;
	}
	if(a[0]!=a[a.length()-1]&&a.length()%2==0){
		cout<<"Second";
		return 0;
	}
	cout<<"First";
	return 0;
}