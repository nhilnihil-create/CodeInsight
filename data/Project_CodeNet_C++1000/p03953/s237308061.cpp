#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;
#define N 200010
ll x[N],dis[N-1],child[N-1],last[N-1];
bool vis[N-1];
ll n,m,k;
int main(){
	cin>>n;
	lol(i,n)cin>>x[i];
	lol(i,n-1)dis[i]=x[i+1]-x[i];
	lol(i,n-1)child[i]=i,vis[i]=false;
	cin>>m>>k;
	lol(i,m){
		ll a;cin>>a;a--;
		swap(child[a-1],child[a]);
	}
	lol(i,n-1){
		if(vis[i]==true)continue;
		ll len=0,pnt=i;
		while(1){pnt=child[pnt],len++;if(pnt==i)break;}
		ll a=i,b=i;
		lol(u,k%len)b=child[b];
		while(1){last[a]=b,vis[a]=true;a=child[a],b=child[b];if(a==i)break;}
	}
	ll sum=x[0];
	cout<<sum<<endl;
	lol(i,n-1){
		sum+=dis[last[i]];
		cout<<sum<<endl;
	}
	return 0;
}
