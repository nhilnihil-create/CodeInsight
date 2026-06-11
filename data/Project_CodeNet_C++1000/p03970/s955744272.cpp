#include<bits/stdc++.h>
using namespace std;
string s1="CODEFESTIVAL2016",s2;
int main(){
	int sum=0;
	cin>>s2;
	for(int i=0;i<16;i++){
		if(s1[i]!=s2[i]) sum++;
	}
	cout<<sum<<endl;
	return 0;
}