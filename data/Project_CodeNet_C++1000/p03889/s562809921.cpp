#include<bits/stdc++.h>
using namespace std;
string a,b;
map<char,char> mp;
int main(){
	mp['q']='p';
	mp['p']='q';
	mp['b']='d';
	mp['d']='b';
	cin>>a;
	for(int i=0;i<a.length();i++){
		b=mp[a[i]]+b;
	}
	if(b==a){
		printf("Yes");
	}
	else printf("No");
	return 0;
}