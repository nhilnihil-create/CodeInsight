#include<bits/stdc++.h>
using namespace std;
string s;
signed main(){
	cin>>s;
	int x,y;
	for(int i=0;i+1<s.size();i++){
		if(s[i]=='A'){
			x=i;
			break;
		}
	}
	for(int i=s.size()-1;i>0;i--){
		if(s[i]=='Z'){
			y=i;
			break;
		}
	}
	cout<<y-x+1;
	return 0;
}