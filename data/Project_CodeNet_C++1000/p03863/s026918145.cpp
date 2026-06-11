#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin>>s;
	int len=s.length();
	if(s[0]==s[len-1]){
		cout<<(len%2==0 ? "First":"Second");
	}
	else{
		cout<<(len%2==1 ? "First":"Second");
	}
	cout<<endl;
	return 0;
}