#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; string s; cin>>n>>s;
	int x=0; int mx=0;
	rep(i,n){
		if(s[i]=='I') x++;
		else x--;
		mx=max(mx,x);
	}
	cout<<mx<<endl;
}