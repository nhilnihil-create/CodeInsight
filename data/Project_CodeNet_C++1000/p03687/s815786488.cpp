#include <bits/stdc++.h>
using namespace std;

string input; 

bool checking(string s){
	for(int i=0; i<s.length(); i++){
		if(s[i]!=s[0])return true;
	}
	return false;
}

int main(){
	cin>>input;
	int minim=1e9; char nummax;
	for(int i=0; i<26; i++){
		string s=input;
		int total=0;
		char nummax=i+'a';
		while(checking(s)){
			total++;
			string t=""; bool fin=true;
			for(int i=0; i<s.length()-1; i++){
				if(s[i]!=nummax&&s[i+1]!=nummax){
					t+=s[i]; fin=false;
				}
				if(s[i]==nummax||s[i+1]==nummax)t+=nummax;
			}
			s=t; 
		}
		minim=min(total,minim);
	}
	cout<<minim<<'\n';
}