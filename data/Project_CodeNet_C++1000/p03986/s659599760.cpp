#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstring>
#include<stdio.h>
using namespace std;
const int maxn=2e5+10;
char c[maxn];
char list[maxn];
int tot,ans;
int main()
{
	char a;
    while(scanf("%c",&a)!=EOF){
    	c[tot++]=a;
	}
	ans=tot-1;
	
    int i=0;
    int head=0;
    while(i<tot-1){
         if(head==0){
         	head++;
         	list[head]=c[i];
         	i++;
		 }
		 else{
		     if(list[head]=='S'&&c[i]=='T'){
		     	ans-=2;
		     	head--;
		     	i++;
			 }
		 	 else{
		 	    head++;
				list[head]=c[i];
				i++; 	
			 }
		 }
	}
	cout<<ans<<endl;
	return 0;
} 