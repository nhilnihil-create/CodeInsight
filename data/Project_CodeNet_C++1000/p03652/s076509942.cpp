#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	int N,M; cin>>N>>M;
	int A[N][M];
	rep(i,0,N)rep(j,0,M){ cin>>A[i][j]; A[i][j]--; }
	int ans = N;
	int id[N] = {}; set<int> st;
	while(st.size() < M-1){
		int cnt[M] = {}; int res = 0; int k;
		rep(i,0,N) cnt[A[i][id[i]]]++;
		rep(i,0,M)if(res < cnt[i]){ res = cnt[i]; k = i; }
		ans = min(ans, res);
		st.insert(k);
		rep(i,0,N)if(A[i][id[i]] == k){
			while(st.count(A[i][id[i]])) id[i]++;
		}//print(id,,N);
	}cout<<ans<<endl;
}