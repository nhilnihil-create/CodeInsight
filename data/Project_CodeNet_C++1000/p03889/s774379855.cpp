#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char s[100001],s2[100001],s3[100001];
int leth(char *ch) 
{
	int i=0;
	for(i=0;ch[i];i++) ;
	return i;
}
int main(){
	cin>>s;
	int flag=1,len=leth(s);
	for(int i=len-1;i>=0;i--){
	    int L=i,R=len-i-1; 
		if (L>R)
		break;
		if(s[L]==s[R])
		flag=0;
		else 
		{
			flag=1;
			break;
		}
	}
	if(!flag)
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	int cnt=0;
	for(int i=0;i<len;i++)
		s2[i]=s[i];
	for(int i=0;i<len;i++){
		if(s2[i]=='b')
		s2[i]='d';
		else if(s2[i]=='d')
		s2[i]='b';
		else if(s2[i]=='p')
		s2[i]='q';
		else if(s2[i]=='q')
		s2[i]='p';
		if(s2[i]==s[i])
		 cnt=1;
		 else
		 	{
		 		cnt=0;
		 		break;
			 }
	}
	if(cnt==1)
	{
		cout<<"Yes"<<endl;
		return 0; 
	}
	
	for(int i=0;i<len;i++)
		s2[len-i-1]=s[i];
		
		for(int i=len-1;i>=0;i--){
	    if(s2[len-i-1]==s[len-i-1])
		 flag=0;
		else 
		{
			flag=1;
			break;
		}
	}
	if(!flag)
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	for(int i=0;i<len;i++){
		if(s2[len-i-1]=='b')
		s2[len-i-1]='d';
		else if(s2[len-i-1]=='d')
		s2[len-i-1]='b';
		else if(s2[len-i-1]=='p')
		s2[len-i-1]='q';
		else if(s2[len-i-1]=='q')
		s2[len-i-1]='p';
		if(s2[len-i-1]==s[len-i-1])
		 cnt=1;
		 else
		 	{
		 		cnt=0;
		 		break;
			 }
	}
	if(cnt==1)
	{
		cout<<"Yes"<<endl;
		return 0; 
	}
	cout<<"No"<<endl;
	return 0;
}
