#include <bits/stdc++.h>
using namespace std;
 
 
 
int main() {
	int w,a,b;
	cin>>w>>a>>b;
	if(a>b) swap(a,b);
	if (a+w<b) cout<<b-a-w;
	else cout<<0;
	
}