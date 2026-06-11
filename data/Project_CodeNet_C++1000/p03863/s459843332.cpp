#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int a[100005];
int main()
{
	string s;
	cin>>s;
	int  sum=0;
	int n=s.size();
	if(s[0]==s[n-1]) sum=n-1;
	else sum=n;
	if(sum%2==1) cout<<"First"<<endl;
	else cout<<"Second"<<endl; 
 } 