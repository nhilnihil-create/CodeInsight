#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[30];

int main(){
	cin>>s;
	
	for(int i=0; i<s.size(); i++){
		cnt[s[i]-'a']++;
		if(cnt[s[i]-'a']>1){
			cout<<"no\n";
			return 0;
		}
	}
	cout<<"yes\n";
}
