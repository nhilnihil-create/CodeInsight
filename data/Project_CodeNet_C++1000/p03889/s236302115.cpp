#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<map>
using namespace std;
const int MAXN=100000+7;
string a;
map<char,char> t;
void Change(string &s){
	for(int i=0;i<(int)s.size();i++) s[i]=t[s[i]];
}
void Reserve(string &s){
	int r=(int)s.size()-1;
	int l=0;
	while(l<r){
		swap(s[l],s[r]);
		l++; r--;
	}
}
int main(){
	t.insert(make_pair('b','d'));
	t.insert(make_pair('d','b'));
	t.insert(make_pair('p','q'));
	t.insert(make_pair('q','p'));
	cin>>a;
	string tmp=a,s=a;
	Reserve(tmp);
	if(tmp==a){
		//cout<<tmp<<endl;
		puts("Yes"); return 0;
	}
	Change(tmp); Change(s);
	string res=s; Reserve(res);
	if(tmp==a||s==a||res==a){
		//cout<<tmp<<' '<<s<<endl;
		puts("Yes"); return 0;
	}
	//cout<<tmp<<' '<<s<<' '<<res<<endl;
	puts("No");
	return 0;
}