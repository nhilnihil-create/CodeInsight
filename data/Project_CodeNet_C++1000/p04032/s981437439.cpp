#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=1e6+5;
int main() {
	string s;cin>>s;
	if(s[0]==s[1]) return cout<<"1 2"<<endl,0;
	for(int i=2;i<s.length();i++) {
		if(s[i]==s[i-1]) return cout<<i<<' '<<i+1<<endl,0;
		vector<char >V;
		for(int j=0;j<=2;j++) 
			V.push_back(s[i-j]);
		sort(V.begin(),V.end());
		if(V[0]==V[1]||V[1]==V[2]) {
			cout<<i-2+1<<' '<<i+1<<endl;
			return 0;
		}
	}
	puts("-1 -1");
    return 0;
}