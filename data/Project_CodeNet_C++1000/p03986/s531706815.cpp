#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
	cin>>s;
	int open=0,sumT=0,banyakT=0;
	for(int i=0; i<s.length(); i++){
		if(s[i]=='S'){
			open++; 
		}
		if(s[i]=='T'&&open>0){
			open--; sumT++;
		}
		if(s[i]=='T')banyakT++;
	}
	cout<<open+banyakT-sumT<<'\n';
}