#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int sx,sy,tx,ty;
	cin>>sx>>sy>>tx>>ty;
	rep(i,tx-sx) cout<<"R";
	rep(i,ty-sy) cout<<"U";
	rep(i,tx-sx) cout<<"L";
	rep(i,ty-sy) cout<<"D";
	cout<<"D";
	rep(i,tx-sx+1) cout<<"R";
	rep(i,ty-sy+1) cout<<"U";
	cout<<"L"<<"U";
	rep(i,tx-sx+1) cout<<"L";
	rep(i,ty-sy+1) cout<<"D";
	cout<<"R"<<endl;
	return 0;
}
