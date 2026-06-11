#include<bits/stdc++.h>
using namespace std;
int main()
{char a[100005],b[100005];
 bool flag=0;
 scanf("%s",a);
 int lena,k=0;
 lena=strlen(a);
 for(int i=lena-1;i>=0;i--)
 {if(a[i]=='b'){
 	b[k]='d';
 	k++;
 }
 else if(a[i]=='d'){
 	b[k]='b';
 	k++;
 }
 else if(a[i]=='p'){
 	b[k]='q';
 	k++;
 }
 else if(a[i]=='q'){
 	b[k]='p';
 	k++;
 }
 }
 for(int i=0;i<lena;i++)
 {if(a[i]!=b[i]){
 	cout<<"No";
 	flag=1;
 	break;
 }
 }
 if(flag==0)cout<<"Yes";
}
