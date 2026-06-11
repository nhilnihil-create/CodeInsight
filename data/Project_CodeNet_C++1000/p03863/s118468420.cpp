#include<bits/stdc++.h>
using namespace std;
inline int Read()
{
	int f=1,num=0;
	char ch=getchar();
	while(0==isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(0!=isdigit(ch)) num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
	return num*f;
}
string s;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>s;
	if(s[0]==s[s.size()-1]){
		if(s.size()%2==1)cout<<"Second"<<endl;
		else cout<<"First"<<endl;
	}
	else{
		if(s.size()%2==1)cout<<"First"<<endl;
		else cout<<"Second"<<endl;
	}
	return 0;
}
