#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

int used[26];

int main(){
	string s;
	cin>>s;
	for(char c:s){
		used[c-'a']=1;
	}
	for(int i=0;i<26;i++){
		if(!used[i]){
			cout<<(char(i+'a'));
			return 0;
		}
	}
	cout<<"None";
	
	
}