#include<iostream>
#include<string>
using namespace std;
char f[256];
int main()
{
	 string s,a;
	 f['b']='d';
	 f['d']='b';
	 f['p']='q';
	 f['q']='p';
	 cin>>s;
	 for(int i=s.length()-1;i>=0;i--)
		 a=a+s[i];
	 //cout<<a<<endl;
	 for(int i=0;i<s.length();i++)
		 a[i]=f[a[i]];
	 if(a==s) cout<<"Yes";
		   else cout<<"No";
}