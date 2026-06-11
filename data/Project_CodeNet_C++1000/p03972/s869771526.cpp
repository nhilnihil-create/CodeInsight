#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;
typedef pair<ll,ll> P;
P a[200010];
int main(){
    ll h,w,x;cin>>w>>h;
    lol(i,w){cin>>x;a[i]=make_pair(x,0);}
    lol(i,h){cin>>x;a[i+w]=make_pair(x,1);}
    sort(a,a+h+w);
    ll ans=0,cnt[2]={0};
    lol(i,h+w){
	int t=a[i].second;
	cnt[t]++;
	if(t==0){
	   ans+=(h-cnt[1]+1)*a[i].first;
	}
	if(t==1){
	   ans+=(w-cnt[0]+1)*a[i].first;
	}
    }
    cout<<ans<<endl;
    return 0;
}
