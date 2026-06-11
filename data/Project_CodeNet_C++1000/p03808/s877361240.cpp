#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	ll N; cin>>N;
	vector<ll>A(N+1);
	vector<ll>d(N);
	ll sum=0;
	rep(i,N){
		cin>>A[i];
		sum+=A[i];
	}
	A[N]=A[0];

	if(sum%((N+1)*N/2)==0){
		ll K=sum/((N+1)*N/2);//操作回数
		rep(i,N){
			d[i]=A[i+1]-A[i];
			d[i]-=K;
		}
		//{d}のうちひとつを+(N-1),その他-1する
		// =すべて-1,1つ+N
		//K回で0にできるか

		//-Kと(+N)*K
		rep(i,N){
			if(d[i]>0 || (-d[i])%N!=0){
				cout<<"NO";
				return 0;
			}
		}
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}

}