#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
typedef long long ll;
int INF=1<<29;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll N;
	cin>>N;
	vector<ll> A(3*N);
	for(int i=0;i<3*N;i++) cin>>A[i];

	//1
	vector<ll> maxtable(3*N);
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	ll sum=0;
	for(int i=0;i<N;i++){
		sum+=A[i];
		pq.push(A[i]);
	}
	maxtable[N-1]=sum;
	for(int i=N;i<2*N;i++){
		if(A[i]>=pq.top()){
			sum+=A[i];
			sum-=pq.top();
			pq.pop();
			pq.push(A[i]);
		}
		maxtable[i]=sum;
	}

	//2
	reverse(A.begin(),A.end());
	vector<ll> mintable(3*N);
	priority_queue<ll> pq2;
	sum=0;
	for(int i=0;i<N;i++){
		sum+=A[i];
		pq2.push(A[i]);
	}
	mintable[N-1]=sum;
	for(int i=N;i<2*N;i++){
		if(A[i]<=pq2.top()){
			sum+=A[i];
			sum-=pq2.top();
			pq2.pop();
			pq2.push(A[i]);
		}
		mintable[i]=sum;
	}
	reverse(mintable.begin(),mintable.end());

	/*for(int i=0;i<3*N;i++) cout<<maxtable[i];
	cout<<endl;
	for(int i=0;i<3*N;i++) cout<<mintable[i];
	cout<<endl;*/

	ll Ans=LLONG_MIN;
	for(int i=N-1;i<2*N;i++) if(maxtable[i]-mintable[i+1]>=Ans) Ans=maxtable[i]-mintable[i+1];
	cout<<Ans<<endl;
	return 0;
}

