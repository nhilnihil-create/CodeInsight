#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,T;
	cin >> N >> T;
	vector<ll> A(N),mn(N),B(N);
	//mx[i] はi番目までのmn
	rep(i,N){
		cin >> A[i];
		if(i==0)mn[i] = A[i];
		else mn[i] = min(mn[i-1],A[i]);
	}
	rep(i,N){
		B[i] = A[i] - mn[i];
	}
	int ans = 0;
	int max = 0;
	rep(i,N){
		if(max==B[i] && max!=0)ans++;
		else if(max<B[i]){
			max = B[i];
			ans = 1;
		}
	}
	cout << ans << endl;
}