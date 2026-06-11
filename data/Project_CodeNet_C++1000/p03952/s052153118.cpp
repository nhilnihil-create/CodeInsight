#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
bool f[241514];
int main(){
	ll n,x;
	cin>>n>>x;
	if(x==1||x==2*n-1)cout<<"No\n";
	else{
		cout<<"Yes\n";
		f[x]=f[x-1]=f[x+1]=1;
		ll cnt=n-2;
		ll now=1;
		while(cnt){
			if(!f[now]){
				cout<<now<<endl;
				cnt--;
			}
			now++;
		}
		cout<<x-1<<endl<<x<<endl<<x+1<<endl;
		cnt=n-2;
		while(cnt){
			if(!f[now]){
				cout<<now<<endl;
				cnt--;
			}
			now++;
		}
	}
	return 0;
}
