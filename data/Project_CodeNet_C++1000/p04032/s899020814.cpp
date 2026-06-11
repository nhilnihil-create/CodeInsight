#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	if(s.size()==2){
		if(s[0]==s[1]){
			cout<<1<<" "<<2<<endl;
		}
		else{
			cout<<-1<<" "<<-1<<endl;
		}
		return 0;
	}
	for(int i=0;i<(int)s.size()-3;i++){
		char a = s[i];
		char b = s[i+1];
		char c = s[i+2];
		if(a==b || a==c || b==c){
			cout<<i+1<<" "<<i+3<<endl;
			return 0;
		}
	}
	cout<<"-1 -1"<<endl;
	return 0;
}