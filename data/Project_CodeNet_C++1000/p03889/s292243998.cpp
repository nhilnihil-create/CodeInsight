#include<bits/stdc++.h>
using namespace std;
char s1[100005],s2[100005];
int main()
{
   cin>>s1;
   int l;
   l=strlen(s1);
   for(int i=0;i<l;i++)
   {
   	s2[i]=s1[l-i-1];
   	//cout<<s2[i]<<endl;
   	if(s2[i]=='b')
    {
 	s2[i]='d';
 	continue;
	} 
	if(s2[i]=='d')
    {
 	s2[i]='b';
 	continue;
	} 
	if(s2[i]=='q')
    {
 	s2[i]='p';
 	continue;
	} 
	if(s2[i]=='p')
    {
 	s2[i]='q';
 	continue;
	} 
   }
   //cout<<s1<<"　"<<s2; 
   int flag=0;
   for(int i=0;i<=l;i++)
   {
   	if(s2[i]!=s1[i])
   	{
   		flag=1;
   		break;
	   }
   }
   if(!flag) cout<<"Yes";
   else cout<<"No";
   return 0;
}