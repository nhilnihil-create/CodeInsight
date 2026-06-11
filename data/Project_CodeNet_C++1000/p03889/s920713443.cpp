#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;
int main(){
	string s,t;
	cin>>s;
	for(int i=s.size()-1;i>=0;i--){
		t+=s[i];
	}
	for(int i=0;i<s.size();i++){
		if(t[i]=='p'){
			t[i]='q';
		}else{
			if(t[i]=='q'){
				t[i]='p';
			}else{
				if(t[i]=='b'){
					t[i]='d';
				}else{
					t[i]='b';
				}
			}
		}
	}
	bool k=1;
	for(int i=0;i<s.size();i++){
		if(t[i]!=s[i]){
			k=0;
		}
	}
	if(k){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	return 0;
}