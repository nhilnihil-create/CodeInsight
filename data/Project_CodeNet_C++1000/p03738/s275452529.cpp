#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

int main(){
	string a,b;
	cin>>a>>b;
	if(sz(a)>sz(b)){
		cout<<"GREATER";
		return 0;
	}
	if(sz(a)<sz(b)){
		cout<<"LESS";
		return 0;
	}
	for(int i=0;i<sz(a);i++){
		if(a[i]!=b[i]){
			if((int)a[i]>(int)b[i]){
				cout<<"GREATER";
				return 0;
			}
			else{
				cout<<"LESS";
				return 0;
			}
		}
	}
	cout<<"EQUAL";
	
	
}
