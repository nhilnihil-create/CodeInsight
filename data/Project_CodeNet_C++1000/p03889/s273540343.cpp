#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
char sa[100010];
int i,n;
int main()
{
	while((sa[n]=getchar())!='\n') n++;
	n--;
	while((sa[i]=='p'&&sa[n-i]=='q')||(sa[i]=='q'&&sa[n-i]=='p')||(sa[i]=='b'&&sa[n-i]=='d')||(sa[i]=='d'&&sa[n-i]=='b')) i++;
	if(i>n/2) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}  