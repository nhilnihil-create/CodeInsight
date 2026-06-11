#include <bits/stdc++.h>
using namespace std;
int main(){
	int sn,i,k=0;
	string s,ss;
	cin>>s;
	ss="CODEFESTIVAL2016";
	sn=s.length();
	for(i=0;i<sn;i++){
		if(s[i]!=ss[i]) k++;
		
	}
	cout<<k<<endl;
}