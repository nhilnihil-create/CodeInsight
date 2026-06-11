#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<int(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define show(x) cout<< #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int vx[]={0,0,-1,1};
int vy[]={1,-1,0,0};
int dx[]={1,0,-1,1,-1,1,0,-1};
int dy[]={1,1,1,0,0,-1,-1,-1};

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a*b/gcd(a,b);}	

const ll mod=1e9+7;
const int INF=INT_MAX/2;
const int N_MAX=100010;

int main(){
	ll k;
	cin>>k;
	vector<ll> ans(50);
	ll lp=k%50;
	for(int i=0;i<50;i++){
		if(i>49-lp)ans[i]=50;
		else ans[i]=49-lp;
	}
	ll d=k/50;
	for(int i=0;i<50;i++)ans[i]+=d;
	cout<<50<<endl;
	for(int  i=0;i<50;i++){
		cout<<ans[i];
		if(i!=49)cout<<" ";
	}
	cout<<endl;
	return 0;
}
