#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
const long long MAXN=1e5+5;
using namespace std;
typedef long long ll;

const ll INF = 1e18;//极大值 

ll a[MAXN];
//queue<ll> be,en;

//priority_queue <ll> p;//优先队列，默认从大到小 
priority_queue <ll,vector<ll>,greater<ll> > be;//从小到大 
priority_queue <ll,vector<ll>,less<ll> > en; //从大到小
ll n;

int main() {
 	ll x;
	cin>>n;
	ll mx=0,mn=0,ans=-INF;
	ll pre[MAXN]={0};
	for(int i=1;i<=3*n;i++){
		cin>>x;
		if(i<=n){
			be.push(x);
			mx+=x; 
		}
		else if(i<=2*n){
			a[i-n]=x;
		}
		else if(i>=2*n+1){
			en.push(x);
			mn+=x;
		}
	}
	pre[n-n]=mx;//pre[0]=pre[n]
	for(int i=1;i<=n;i++){
		mx+=a[i];
		be.push(a[i]);
		if(be.size()>n){
			mx-=be.top();
			be.pop();
		}
		pre[i]=max(pre[i-1],mx);
	}
	ans=max(ans,pre[n]-mn);
	for(int i=n;i>=1;i--){
		en.push(a[i]);
		mn+=a[i];
		if(en.size()>n){
			mn-=en.top();
			en.pop();
		}
		ans=max(ans,pre[i-1]-mn);
	}
	cout<<ans<<endl;
 	return 0;
 }
 