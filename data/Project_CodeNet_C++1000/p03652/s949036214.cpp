#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<iomanip>
#define mod 1000000007
using namespace std;
typedef long long ll;
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)
#define mad(a,b) a=(a+b)%mod
#define mul(a,b) a=a*b%mod

#define N 310
ll n,m;
ll a[N][N];
bool th[N];
ll solve(){
    ll cnt[N];
    for(int i=0;i<m;i++){
	cnt[i]=0;
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    if(th[a[i][j]]){
		cnt[a[i][j]]++;
		break;
	    }
	}
    }
    ll ma=-1,pnt=-1;
    for(int i=0;i<m;i++){
	if(cnt[i]>ma){
	    ma=cnt[i];
	    pnt=i;
	}
    }
    th[pnt]=0;
    return ma;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    cin>>a[i][j];
	    a[i][j]--;
	}
    }
    for(int i=0;i<m;i++)th[i]=1;
    ll ans=1e17;
    for(int i=0;i<m;i++){
	chmin(ans,solve());
    }
    cout<<ans<<endl;
}


