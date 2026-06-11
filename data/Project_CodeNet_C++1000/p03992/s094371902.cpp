#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m,a,b,c,sum=0;
	string s;
	cin>>s;
	for(int i=0;i<12;i++){
	    if(i!=3){
	        cout<<s[i];
	    }
	    else{
	        cout<<s[i]<<' ';
	    }
	}
	cout<<'\n';
	return 0;
}
