#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define INF      (int)1e9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
typedef pair<int,int> pii;
template<class Type_a,class Type_b> bool chmax(Type_a &a,const Type_b &b){if(a<b){a=b;return true;}return false;}
template<class Type_a,class Type_b> bool chmin(Type_a &a,const Type_b &b){if(a>b){a=b;return true;}return false;}
template<class Type> Type igcd(Type x,Type y){return (y==0)?x:igcd(y,x%y);}
template<class Type> Type ilcm(Type x,Type y){return x/igcd(x,y)*y;}
template<class Type> void line(const Type &a){int cnt=0;for(const auto &elem:a){if(cnt++)cout<<' ';cout<<elem;}cout<<endl;}

//参加者解答参考.
int main(){
	int w,h;
	cin>>w>>h;
	
	priority_queue<pii,vector<pii >,greater<pii > > que;//pii(cost,jud)
	REP(i,w){
		int p;
		cin>>p;
		que.push(pii(p,0));
	}
	REP(i,h){
		int q;
		cin>>q;
		que.push(pii(q,1));
	}
	
	llong ans=0;
	int nw=w+1,nh=h+1;
	while(!que.empty()){
		int cost;
		int jud;
		tie(cost,jud)=que.top();
		que.pop();
		
		if(jud==0){
			ans+=(llong)cost*nh;
			nw--;
		}else{
			ans+=(llong)cost*nw;
			nh--;
		}
	}
	
	cout<<ans<<endl;
}