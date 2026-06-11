#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	int N; long K;cin>>N>>K;
	long A[N],B[N];
	rep(i,0,N) cin>>A[i]>>B[i];
	long ans = 0, res = 0; long t = 0;
	for(int i = 29; i >= 0; i--){
		if(K & (1<<i)){
			res = 0;
			rep(j,0,N){
				res += B[j];
				for(int k = 29; k >= i; k--){
					if( (A[j] & (1<<k)) > (t & (1<<k)) ){ res -= B[j]; break; }
				}
			}ans = max(ans, res);
			t = t | (1<<i);
		}
	}
    res = 0;
    rep(j,0,N){
        res += B[j];
        for(int k = 29; k >= 0; k--){
            if( (A[j] & (1<<k)) > (K & (1<<k)) ){ res -= B[j]; break; }
        }
    }ans = max(ans, res);
    cout<<ans<<endl;
}