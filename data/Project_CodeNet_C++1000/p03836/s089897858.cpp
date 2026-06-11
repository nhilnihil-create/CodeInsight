#include<bits/stdc++.h>
#define turbo(){	\
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL); \
}
using namespace std;
typedef long long ll;
int main()
{
	turbo();
	string s="",s1="";
	int x,y,tx,ty,i;
	cin>>x>>y>>tx>>ty;
	int j=y;
	s1+="L";
	while(j!=ty){
		s+="U";
		j++;
		s1+="U";
	}
	j=x;
	s1+="U";
	while(j!=tx){
		s+="R";
		s1+="R";
		j++;
	}
	s1+="RD";
	int sz=s.size(); 
	for(i=0;i<sz;i++){
		if(s[i]=='U'){
			s+="D";
		}
		else{
			s+="L";
		}
	}
	sz=s1.size();
	for(i=0;i<sz;i++){
		if(s1[i]=='U'){
			s1+="D";
		}
		else if(s1[i]=='D'){
			s1+="U";
		}
		else if(s1[i]=='L'){
			s1+="R";
		}
		else{
			s1+="L";
		}
	}
	s+=s1;
	cout<<s<<endl;
	return 0;	
}
