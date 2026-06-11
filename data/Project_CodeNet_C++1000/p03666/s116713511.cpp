#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair 
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)

int main(){
	//input
	ll N,A,B,C,D; cin>>N>>A>>B>>C>>D;
	N--;
	
	//solve
	ll L=-(D*N);
	bool ans=false;
	rep(i,N+1){
		ll tmp=L+i*(C+D); //端
		if(tmp<=B-A && B-A<=tmp+N*(D-C)) ans=true;
	}

	//output
	if(ans) cout<<"YES";
	else cout<<"NO";
}