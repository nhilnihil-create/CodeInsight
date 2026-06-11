#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
const long mod=1e9+7;
int main(){
	int N;cin>>N;
	int cnt[N] = {}; int a;
	rep(i,0,N){
		cin>>a; cnt[a]++;
		cnt[abs(N - 2*i - 1)]--;
	}
	rep(i,0,N)if(cnt[i]){
		cout<<0<<endl;
		return 0;
	}
    long res = 1;
	rep(i,0,N/2) (res*=2)%=mod;
    cout<<res<<endl;
}