#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#define mod 1000000007
using namespace std;
typedef long long ll;
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)
#define mad(a,b) a=(a+b)%mod
#define mul(a,b) a=a*b%mod

ll n,a[110],cnt[110];
bool solve(){
    cin>>n;
    for(int i=1;i<n;i++)cnt[i]=0;
    ll ma=-1;
    for(int i=0;i<n;i++){
	cin>>a[i];
	cnt[a[i]]++;
	chmax(ma,a[i]);
    }
    for(int i=0;i<(ma+1)/2;i++){
	cnt[ma-i]-=2;
    }
    if(ma%2==0)cnt[ma/2]--;
    for(int i=1;i<=(ma+1)/2;i++)if(cnt[i]>0)return 0;
    for(int i=1;i<n;i++)if(cnt[i]<0)return 0;
    return 1;
}
int main(){
    if(solve()==0)cout<<"Impossible"<<endl;
    else cout<<"Possible"<<endl;
}


