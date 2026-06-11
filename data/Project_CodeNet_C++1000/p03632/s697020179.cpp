#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b,c,d;
	cin>>a>>b>>c>>d;
	if(a>=c && b <=d) cout<< b-a;
	else if(c>=a && d <=b) cout<< d-c;
	else if(d<a) cout<<0;
	else if(b<c) cout<<0;
	else if(a>c) cout<<d-a;
	else cout<<b-c;
	return 0;
}