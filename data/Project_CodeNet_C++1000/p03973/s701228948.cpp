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
	int n;
	cin>>n;
	ll p;
	cin>>p;
	ll t=p-1;
	ll m=2;

	rep(i,n-1){
		cin>>p;
		if(p>m){
			t+=(p-1)/m;
		}
		if(p==m)m++;
	}
	cout<<t<<endl;
	return 0;
}
