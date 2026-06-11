#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ll cost=0;
	ll N,A,B;
	cin>>N>>A>>B;
	vector<ll> X(N);
	for(int i=0;i<N;i++) cin>>X[i];
	for(int i=0;i<N-1;i++){
		ll dist=X[i+1]-X[i];
		if(dist*A>B) cost+=B;
		else cost+=(A*dist);
	}
	cout<<cost<<endl;
}