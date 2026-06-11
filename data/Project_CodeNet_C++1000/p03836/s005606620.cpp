#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,y,xx,yy;
	cin>>x>>y>>xx>>yy;
	xx-=x;
	yy-=y;
	vector<char>path;
	for(int i=0; i<xx; i++) path.push_back('R');
	for(int i=0; i<yy; i++) path.push_back('U');
	for(int i=0; i<xx; i++) path.push_back('L');
	for(int i=0; i<yy; i++) path.push_back('D');
	path.push_back('D');
	for(int i=0; i<xx+1; i++) path.push_back('R');
	for(int i=0; i<yy+1; i++) path.push_back('U');
	path.push_back('L');
	
	path.push_back('U');
	for(int i=0; i<xx+1; i++) path.push_back('L');
	for(int i=0; i<yy+1; i++) path.push_back('D');
	path.push_back('R');
	for(int i=0; i<path.size(); i++) cout<<path[i];
}