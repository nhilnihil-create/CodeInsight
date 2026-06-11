#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string o,e; cin>>o>>e;
	int ko=o.size();
	int ke=e.size();
	rep(i,ko){
			cout<<o[i];
			if(i==ke) continue;
			else cout<<e[i];
	}
}