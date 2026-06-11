#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main(){
	fast;
	int sx,sy,tx,ty,x,y;
	cin>>sx>>sy>>tx>>ty;
	x=abs(sx-tx);
	y=abs(sy-ty);
	string s;
	for(int i=1;i<=y;i++)
		s+="U";
	for(int i=1;i<=x;i++)
		s+="R";
	for(int i=1;i<=y;i++)
		s+="D";
	for(int i=1;i<=x;i++)
		s+="L";
	s+="L";
	for(int i=1;i<=y+1;i++)
		s+="U";
	for(int i=1;i<=x+1;i++)
		s+="R";
	s+="D";
	s+="R";
	for(int i=1;i<=y+1;i++)
		s+="D";
	for(int i=1;i<=x+1;i++)
		s+="L";
	s+="U";
	cout<<s;
	return 0;
}

