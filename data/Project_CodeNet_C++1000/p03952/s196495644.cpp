#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair 
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define rrep(i,n) for(ll i=n-1;i>=0;i--)
#define rrep1(i,n) for(ll i=n;i>=1;i--)
#define FOR(i,a,b) for(ll i=a;i<b;i++)

int main(){
	ll N,x; cin>>N>>x;
	vector<ll> ans(2*N);
	if(x==1 || x==2*N-1) cout<<"No";
	else{
		if(N==2){
			cout<<"Yes"<<endl;
			cout<<1<<endl<<2<<endl<<3;
		}
		else if(x!=2){
			ll tmp=1;
			rep1(i,2*N-1){
				if(i==N-1) ans[i]=x-1;
				else if(i==N) ans[i]=x;
				else if(i==N+1) ans[i]=x+1;
				else if(i==N+2) ans[i]=x-2;
				else{
					ans[i]=tmp++;
					if(ans[i]>=x-2) ans[i]+=4;
				}
			}
			cout<<"Yes"<<endl;
			rep1(i,2*N-1) cout<<ans[i]<<endl;
		}
		else{
			ll tmp=1;
			rep1(i,2*N-1){
				if(i==N-1) ans[i]=x+2;
				else if(i==N) ans[i]=x;
				else if(i==N+1) ans[i]=x-1;
				else if(i==N+2) ans[i]=x+1;
				else{
					ans[i]=tmp++;
					if(ans[i]>=x-1) ans[i]+=4;
				}
			}
			cout<<"Yes"<<endl;
			rep1(i,2*N-1) cout<<ans[i]<<endl;
		}
	}
}