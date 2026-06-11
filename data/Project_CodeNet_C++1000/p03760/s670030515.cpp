#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int main(){
	cin>>s1>>s2;
	
	for(int i=0; i<s2.size(); i++){
		cout<<s1[i]<<s2[i];
	}
	if(s1.size()>s2.size()) cout<<s1[s1.size()-1];
	cout<<endl;
}
