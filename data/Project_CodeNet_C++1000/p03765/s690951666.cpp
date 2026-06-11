#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+5;
int T,CS[MAX],CT[MAX];
string s,t;

int main() {
	//freopen("input","r",stdin);
	cin>>s>>t>>T;
	for(int i=1;i<=s.size();i++)
		CS[i]=CS[i-1]+(s[i-1]=='B');
	for(int i=1;i<=t.size();i++)
		CT[i]=CT[i-1]+(t[i-1]=='B');
	int l1,r1,l2,r2;
	while(T--) {
		cin>>l1>>r1>>l2>>r2;
		int sumA=(r1-l1+1)+(CS[r1]-CS[l1-1]);
		int sumB=(r2-l2+1)+(CT[r2]-CT[l2-1]);
		cout<<(sumA%3==sumB%3?"YES":"NO")<<'\n';
	}
}
