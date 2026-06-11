#include<bits/stdc++.h>
using namespace std;
string s1,s2;
map<char,char>mp;
void init(){
	cin>>s1;
	s2=s1;
	mp['b']='d'; mp['d']='b'; mp['q']='p'; mp['p']='q';
}
int main(){
	init();
	reverse(s2.begin(),s2.end());
	for(int i=0;i<s2.size();i++)
	    s2[i]=mp[s2[i]];
	if(s1==s2)
	    cout<<"Yes\n";
	else
	    cout<<"No\n";
	return 0;
}