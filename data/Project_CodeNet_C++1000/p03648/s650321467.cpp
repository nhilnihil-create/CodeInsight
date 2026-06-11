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
int main(){
	ll K;
	cin>>K;
	int N = 50;
	vector<ll> a(N,N-1);
	rep(i,N) a[i] += K/N;
	rep(i,K%N){
		rep(j,N){
			if(j==i) a[j] += N;
			else a[j]--;
		}
	}
	cout<<N<<endl;
	rep(i,N) cout<<a[i]<<" ";
	puts("");
}