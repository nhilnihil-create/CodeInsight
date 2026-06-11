#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	string ans = "";
	for(char ch:s){
		if(ch=='0'){
			ans+='0';
		}
		else if(ch=='1'){
			ans+='1';
		}
		else if(ch=='B' && ans!=""){
			ans.erase(ans.end()-1);
		}
	}
	cout<<ans<<endl;
}