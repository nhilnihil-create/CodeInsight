#include<bits/stdc++.h>
#define ll long long
#define reg register
using namespace std;
string s;
map<char,int>a;
int main()
{
    a['p']=1;
	a['d']=2;
	a['q']=3;
	cin>>s;
	s=" "+s; 
    for(reg int l=s.length()-1,i=1;i<=(l>>1)+1;i++)
	if(a[s[i]]^((a[s[l-i+1]]+2)%4))return puts("No"),0;
    return puts("Yes"),0;
}