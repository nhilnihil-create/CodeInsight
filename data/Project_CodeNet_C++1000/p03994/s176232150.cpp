#include <bits/stdc++.h>
using namespace std;
string s;
int K; 
int main(){
	cin>>s>>K;
	for(int i=0;i<s.size()&&K;i++){
		if(s[i]=='a')continue;
		int n='z'+1-s[i];
		if(n<=K){
			s[i]='a';
			K-=n;
		}
	}
	int d=s[s.size()-1]-'a';
	d+=K;
	d%=26;
	s[s.size()-1]='a'+d;
	cout<<s;
	return 0;
}
