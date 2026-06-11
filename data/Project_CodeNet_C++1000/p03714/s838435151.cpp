#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(a,n) rep(i,0,n){ cout<<(i ? " ":"")<<a[i]; }cout<<endl;
#define pprint(a,m,n) rep(j,0,m){ print(a[j],n); }
const int mod = 1e9+7;
const int size=1e5;
const long INF=1e14;
int main(){
	int N;cin>>N;
	long A[3*N];
	rep(i,0,3*N) cin>>A[i];
	vector<pair<long,long>> vp(3*N);
	long sum=0;priority_queue<long> pqf;
	rep(i,0,N){ sum+=A[i]; pqf.push(-A[i]); }
	rep(i,N,2*N+1){
		vp[i].first=sum;
		sum+=A[i]; pqf.push(-A[i]);
	    sum+=pqf.top(); pqf.pop();
	}
	sum=0;priority_queue<long> pqs;
	for(int i=3*N-1;i>=2*N;i--){ sum+=A[i]; pqs.push(A[i]); }
	for(int i=2*N;i>=N;i--){
		vp[i].second=sum;
		sum+=A[i-1]; pqs.push(A[i-1]);
		sum-=pqs.top(); pqs.pop();
	}
    /*rep(i,N,2*N+1){
        cout<<vp[i].first<<" "<<vp[i].second<<endl;
    }*/
	long ans=-INF;
	rep(i,N,2*N+1) ans=max(ans,vp[i].first-vp[i].second);
	cout<<ans<<endl;
}