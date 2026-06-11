#include <bits/stdc++.h>
using namespace std;
int main(){
	string a="CODEFESTIVAL2016",b;
	int jsq=0;
	cin>>b;
	for(int i=0;i<=15;i++){
		if(b[i]!=a[i]){
			jsq++;
		}
	}
	cout<<jsq<<endl;
	return 0;
}