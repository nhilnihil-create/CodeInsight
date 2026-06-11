#include <bits/stdc++.h>
using namespace std;

int main(){
	string a,b,c;
	cin>>a>>b>>c;
	int lena=a.length();
	int lenb=b.length();
	if(a[lena-1]==b[0] && b[lenb-1]==c[0])
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}