#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define vi vector<int>
#define pb(a) push_back(a)
using namespace std;

typedef long long ll;

typedef pair<ll,int> P1;
typedef pair<int,P1> P2;
const int inf=1000000000;
struct edge{
	int myc,to,c,cost;
};
struct pos{
	int to,cost,color;
};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

#define MAX_N 100002

map<int,int> dp[MAX_N];
vector<edge> G1[MAX_N],G2[MAX_N],G3[1000002];
int dp1[MAX_N];
priority_queue<P2,vector<P2>,greater<P2>> que;

P1 a[200001]={};

int main() {
	ll w,h;
	cin>>w>>h;
	ll p=0,q=0;

	rep(i,w){
		cin>>p;
		a[i]=P1(p,1);
	}
	rep(i,h){
		cin>>q;
		a[i+w]=P1(q,0);
	}
	sort(a,a+h+w);
	p=0;
	q=0;
	ll t=0;
	rep(i,h+w){
		ll n=a[i].first;
		ll r=a[i].second;
		if(r==1){
			t+=n*(h+1-q);
			p++;
		}else{
			t+=n*(w+1-p);
			q++;
		}
	}
	cout<<t<<endl;
	return 0;
}
