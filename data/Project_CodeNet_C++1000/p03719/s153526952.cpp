#include <bits/stdc++.h>

using namespace std;

bool bijiaodaxiao(int a,int b,int c){
	if(a <= c && c <= b)return true;
	else return false;
}

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(bijiaodaxiao(a,b,c))cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
	return 0;
}