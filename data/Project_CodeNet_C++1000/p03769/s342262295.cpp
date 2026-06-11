#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int main(){
	ll n;cin>>n;n++;
	deque<int>f{1},r{1};
	int p=2;
	bool flag=false;
	for(int i=40;i>=0;i--){
		if(!flag){
			if(n>>i&1)flag=true;
			continue;
		}
		if(n>>i&1){//+1
			f.push_back(p);
			r.push_front(p);
			p++;
		}
		if(i){//*2
			f.push_back(p);
			r.push_back(p);
			p++;
		}
	}
	for(int i:r)f.push_back(i);
	cout<<f.size()<<endl;
	rep(i,f.size()){
		if(i)printf(" ");
		cout<<f[i];
	}
	cout<<endl;
}