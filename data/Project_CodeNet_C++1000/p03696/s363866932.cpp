#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
int mod = 1000000000+7;

int main(){

	int n;
	string s;
	cin>>n>>s;
	
	string s1="",s2="";
	int l=0;
	rep(i,n){
		if(s[i]=='(')l++;
		else {
			if(l>0)l--;
			else s1+='(';
		}
	}
	rep(i,l)s2+=')';

	cout<<s1<<s<<s2<<endl;;

	return 0;
}
