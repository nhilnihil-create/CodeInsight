//解説AC
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string s; cin>>s;
	ll ans=0;
	for(int i=0; i<(1<<(s.size()-1)); i++){
		string now=""; now+=s[0];
		for(int j=0; j<s.size()-1; j++){
			if(i &(1<<j)) now+="+";
			now+=s[j+1];
		}
		ll sum=0;
		int pos=0;
		while(now.find("+",pos)!=string::npos){
			int npos=now.find("+",pos);
			sum+=stoll(now.substr(pos,npos-pos));
			pos=npos+1;
		}
		sum+=stoll(now.substr(pos));
		ans+=sum;
	}
	cout<<ans<<endl;
}