#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
int main(){
	string s; cin>>s;
	rep(i,19){
		if(s[i]==',') cout<<" ";
		else cout<<s[i];
	}
	cout<<endl;
}