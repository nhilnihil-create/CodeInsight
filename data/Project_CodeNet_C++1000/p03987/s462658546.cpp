#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5+1;
const long inf=1e14;
int main(){
	int N;cin>>N;
	int a;int id[N+1];
	rep(i,1,N+1){ cin>>a; id[a] = i; }
	long ans = 0; long x,y;
	set<long> st;
	st.insert(0); st.insert(N+1);
	rep(i,1,N+1){
		st.insert(id[i]);
		auto it = st.find(id[i]);
		it--; x = *it;
		it++; it++; y = *it;
		ans += (id[i] - x) * (y - id[i]) * i;
	}cout<<ans<<endl;
}