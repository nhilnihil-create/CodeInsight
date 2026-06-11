#include <bits/stdc++.h>

using namespace std;

bool ok(vector<int>&a,int x,int y){
	int cnt=0;
	for(int i=0;i<a.size();i++){
		if(a[i]==x || a[i]==y)cnt++;
	}
	return cnt==2;
}

int main(){
	int x,y;
	cin>>x>>y;
	vector<int> a={1,3,5,7,8,10,12},b={4,6,9,11},c={2};
	if(ok(a,x,y) || ok(b,x,y) || ok(c,x,y)){
		cout<<"Yes";
	}
	else cout<<"No";
	
}