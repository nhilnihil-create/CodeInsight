#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0),ios::sync_with_stdio(false);
	string s;
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(i&1)continue;
		cout<<s.at(i);
	}
}