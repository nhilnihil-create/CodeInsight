#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
inline int read(){
    int x=0,f=1;char ch=getchar();
    while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
    while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
int n;
string s;
void check(char c1,char c2){
	string t="";
	t+=c1;
	t+=c2;
	for(int i=1;i<s.size()-1;i++){
		if(s[i]=='o'&&t[i]=='S'){
			t+=t[i-1];
		}
		if(s[i]=='o'&&t[i]=='W'){
			if(t[i-1]=='W')t+='S';
			if(t[i-1]=='S')t+='W';
		}
		if(s[i]=='x'&&t[i]=='S'){
			if(t[i-1]=='W')t+='S';
			if(t[i-1]=='S')t+='W';
		}
		if(s[i]=='x'&&t[i]=='W'){
			t+=t[i-1];
		}
	}
	for(int i=0;i<t.size();i++){
		int k=i-1,p=i+1;
		if(k<0)k=n-1;
		if(p==n)p=0;
		if(t[i]=='W'){
			if(s[i]=='o'){
				if(t[k]==t[p])return ;
			}
			if(s[i]=='x'){
				if(t[k]!=t[p])return ;
			}
		}
		if(t[i]=='S'){
			if(s[i]=='o'){
				if(t[k]!=t[p])return ;
			}
			if(s[i]=='x'){
				if(t[k]==t[p])return ;
			}
		}
	}
	cout<<t<<endl;
	exit(0);
}
int main(){
	cin>>n>>s;
	check('S','W');
	check('S','S');
	check('W','S');
	check('W','W');
	cout<<-1<<endl;
	return 0;
}