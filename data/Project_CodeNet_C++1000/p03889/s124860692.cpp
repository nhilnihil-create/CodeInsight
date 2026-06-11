#include<iostream>
#include<cstdio>
using namespace std;
string s;
char c[100];
int main(){
	cin>>s;
	int b='b';
	int d='d';
	int p='p';
	int q='q';
	c[b]='d';
	c[p]='q';
	c[q]='p';
	c[d]='b';
	int l=s.size();
	if(s.size()%2==1){
		cout<<"No"<<endl;
		return 0;
	}
	for(int i=l/2-1;i>=0;i--){
		if(c[s[i]]!=s[l/2+l/2-1-i]){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}