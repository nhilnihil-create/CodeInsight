#include<bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 1002
#define i197 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<P1,ll> P2;
const ll INF=100000000000000001;
struct edge{int to,cost;};
struct pos{
	int x,y,cost;
};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};

int main() {

	string s,t;
	cin>>s;
	rrep(i,s.size()){
		if(s[i]=='p')t+='q';
		if(s[i]=='q')t+='p';
		if(s[i]=='b')t+='d';
		if(s[i]=='d')t+='b';
	}
	if(s==t)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}
