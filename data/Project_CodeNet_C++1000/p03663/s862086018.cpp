#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
typedef long long ll;
ll N;
int cnt;
bool query(ll x){
	cnt++;
	cout<<"? "<<x<<endl;
	char c;
	cin>>c;
	return c=='Y';

//	return (x<=N && to_string(x)<=to_string(N)) || (x>N && to_string(x)>to_string(N));
}

void ans(ll x){
	cout<<"! "<<x<<endl;
}
int main(){
//	cin>>N;


	ll x = 0;
	rep(d,9){
		x*=10;
		int ub = 9, lb = (d==0?0:-1);
		while(ub-lb>1){
			ll m = (ub+lb)/2;
			ll nx = x+m;
			ll tmp = nx;
			while(tmp<1e11) tmp=tmp*10+9;
			if(query(tmp)) ub = m;
			else lb = m;
		}
		x += ub;
	}

	rep1(d,9){
		ll t = 1;
		rep(i,d) t *= 10;
		if(!query(t)){
			rep(j,9-d) x/=10;
			ans(x);
			return 0;
		}
	}

	rep1(d,10){
		ll t = 1;
		rep(i,d) t *= 10;
		t--;
		if(query(t)){
			ans((t+1)/10);
			return 0;
		}
	}
}
