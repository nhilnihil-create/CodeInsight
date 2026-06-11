#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pb(x) push_back(x) 
#define bg begin()
#define ed end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
const ll INF=-100000000000000000;

//a,b x
int main(){
	ll N; cin>>N;
	vector<ll> A(3*N+1);
	rep1(i,3*N) cin>>A[i];
	//1,2,3,4,......,3N-2,3N-1,3N
	// 1,2,3,....,3N-3,3N-2,3N-1
	
	priority_queue<ll,vector<ll>,greater<ll>> MAX;
	vector<ll> MAXsum(2*N+1,0);
	ll tmp=0;
	for(int i=1;i<=N;i++){
		MAX.push(A[i]);
		tmp+=A[i];
	}
	MAXsum[N]=tmp;
	for(int i=N+1;i<=2*N;i++){
		if(A[i]>MAX.top()){
			MAXsum[i]=MAXsum[i-1]+(A[i]-MAX.top());
			MAX.pop();
			MAX.push(A[i]);
		}
		else MAXsum[i]=MAXsum[i-1];
	}

	priority_queue<ll> MIN;
	vector<ll> MINsum(2*N+1,0);
	tmp=0;
	for(int i=3*N;i>=2*N+1;i--){
		MIN.push(A[i]);
		tmp+=A[i];
	}
	MINsum[2*N]=tmp;
	for(int i=2*N;i>=N+1;i--){
		if(A[i]<MIN.top()){
			MINsum[i-1]=MINsum[i]-(MIN.top()-A[i]);
			MIN.pop();
			MIN.push(A[i]);
		}
		else MINsum[i-1]=MINsum[i]; 
	}

	ll ans=INF;
	for(int i=N;i<=2*N;i++){
		ans=max(ans,MAXsum[i]-MINsum[i]);
	}
	cout<<ans;
}