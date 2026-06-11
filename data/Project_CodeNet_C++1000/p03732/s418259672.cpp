#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
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
typedef pair<string,string> Ps;
const ll INF=1000000000000000001;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};
struct pos{
	// 1 変数を入れる
	int x,y,cost;
};
ll s[101]={},s2[101]={},s3[101]={},s4[101]={};

int main() {

	int n;
	ll w;
	cin>>n>>w;
	int w1=2,w2=1,w3=1,w4=1;
	ll W,u;
	cin>>W>>u;
	s[1]=u;
	rep(i,n-1){
		ll x,y;
		cin>>x>>y;
		if(x==W){
			s[w1]=y;
			w1++;
		}
		if(x==W+1){
			s2[w2]=y;
			w2++;
		}
		if(x==W+2){
			s3[w3]=y;
			w3++;
		}
		if(x==W+3){
			s4[w4]=y;
			w4++;
		}
	}
	sort(s,s+w1,greater<ll>());
	sort(s2,s2+w2,greater<ll>());
	sort(s3,s3+w3,greater<ll>());
	sort(s4,s4+w4,greater<ll>());

	ll i1=0,ma=0,u1=0;
	rep(i,w1){
		ll i2=0,u2=0;
		u1+=s[i];
		i1+=W;
		if(i==w1-1){
			i1=0;
			u1=0;
		}
		rep(j,w2){
			ll i3=0,u3=0;
			u2+=s2[j];
			i2+=W+1;
			if(j==w2-1){
				i2=0;
				u2=0;
			}
			rep(k,w3){
				ll i4=0,u4=0;
				u3+=s3[k];
				i3+=W+2;
				if(k==w3-1){
					i3=0;
					u3=0;
				}
				rep(l,w4){
					u4+=s4[l];
					i4+=W+3;
					if(l==w4-1){
						i4=0;
						u4=0;
					}
					if(i1+i2+i3+i4<=w){
						ma=max(ma,u1+u2+u3+u4);
					}
				}
			}
		}
	}
	cout<<ma<<endl;

	return 0;
}
