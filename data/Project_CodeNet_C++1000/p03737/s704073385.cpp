#include <bits/stdc++.h>
#include <string>
using namespace std;

int d,e,f;
string a,b,c;

int main(){
	cin>>a>>b>>c;
	d=a.length();
	e=b.length();
	f=c.length();
	a.erase(1,d-1);
	b.erase(1,e-1);
	c.erase(1,f-1);
	a[0]=a[0]-'a'+'A';
	b[0]=b[0]-'a'+'A';
	c[0]=c[0]-'a'+'A';
	cout<<a<<b<<c;
}
