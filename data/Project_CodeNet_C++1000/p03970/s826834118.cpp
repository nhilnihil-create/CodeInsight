#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	string a="CODEFESTIVAL2016";
	cin>>s;
	int q=16;
	for(int i=0;i<16;i++){
		q-=(a[i]==s[i])?1:0;
	}
	cout<<q<<endl;
	return 0; 
}
