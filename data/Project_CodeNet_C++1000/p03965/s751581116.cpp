#include<bits/stdc++.h>
using namespace std;

int main(){
	int g=0,p=0;
	int w=0,l=0;
	string s;

	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='g'){
			if(p<g){p++;w++;}
			else{g++;}
		}
		else{
			if(p<g){p++;}
			else{g++;l++;}
		}
	}
	cout<<w-l<<endl;
}