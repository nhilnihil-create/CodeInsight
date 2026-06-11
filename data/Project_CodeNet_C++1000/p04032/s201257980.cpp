#include<bits/stdc++.h>
using namespace std;

#define ll long long int

	
	
int main(){
	
	string s;
	cin>>s;
	
	int ansa = -1;
	int ansb = -1;
	if(s.length() == 2){
		if(s[0] == s[1])
			ansa = 1 , ansb = 2;
	}else if(s.length() > 2){
		for(int i=0;i<s.length()-2;i++){
				if(s[i] == s[i+1] || s[i] == s[i+2] || s[i+1] == s[i+2]){
					ansa = i+1;
					ansb = i+1+2;
					break;
				}
		}
}
	cout<<ansa<<" "<<ansb<<endl;
	
}
