#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define sz(c) ((int)(c).size())

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> PP;
//const int MAX=;

template <typename T,typename E>
struct SegmentTree{
	using F = function<T(T,T)>;
	using G = function<T(T,E)>;
	using H = function<E(E,E)>;
	int n,height;
	F f;
	G g;
	H h;
	T ti;
	E ei;
	vector<T> dat;
	vector<E> laz;
	  SegmentTree(F f,G g,H h,T ti,E ei):
	    f(f),g(g),h(h),ti(ti),ei(ei){}
  
	void init(int n_){
		n=1;height=0;
		while(n<n_) n<<=1,height++;
		dat.assign(2*n,ti);
		laz.assign(2*n,ei);
	}
	void build(const vector<T> &v){
		int n_=v.size();
		init(n_);
		for(int i=0;i<n_;i++) dat[n+i]=v[i];
		for(int i=n-1;i;i--)dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
	}
	inline T reflect(int k){
		return laz[k]==ei?dat[k]:g(dat[k],laz[k]);
	}
	inline void eval(int k){
		if(laz[k]==ei) return;
		laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);
		laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);
		dat[k]=reflect(k);
		laz[k]=ei;
	}
	inline void thrust(int k){
		for(int i=height;i;i--) eval(k>>i);
	}
	inline void recalc(int k){    
		while(k>>=1)dat[k]=f(reflect((k<<1)|0),reflect((k<<1)|1));
	}
	void update(int a,int b,E x){
		thrust(a+=n);
		thrust(b+=n-1);
		for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
			if(l&1) laz[l]=h(laz[l],x),l++;
			if(r&1) --r,laz[r]=h(laz[r],x);
		}
		recalc(a);
		recalc(b);
	}
	void set_val(int a,T x){
		thrust(a+=n);
		dat[a]=x;laz[a]=ei;
		recalc(a);
	}
	T query(int a,int b){
		thrust(a+=n);
		thrust(b+=n-1);
		T vl=ti,vr=ti;
		for(int l=a,r=b+1;l<r;l>>=1,r>>=1) {
			if(l&1) vl=f(vl,reflect(l++));
			if(r&1) vr=f(reflect(--r),vr);
		}
		return f(vl,vr);
	}
};

int main(){
	int N,M;
	cin>>N>>M;
	priority_queue<PP, vector<PP>, greater<PP>> que;
	rep(i,N){
		int l, r;
		cin>>l>>r;
		r++;
		PP p=make_pair(r-l, make_pair(l,r));
		que.push(p);
	}
	
	auto f=[](int a, int  b){return a+b;};
	SegmentTree<int,int> seg(f,f,f,0,0);
	
	seg.init(M+1);
	int mb=N;
  	bool rem=true;
	rep1(d,M){
		while(rem){
			PP pp=que.top();
			if(pp.first<d){
				P p=pp.second;
				int l=p.first;
				int r=p.second;
				seg.update(l,r,1);
				que.pop();
				mb--;
				
			}
			else break;
			if(que.empty()) rem=false;
		}
		int ans=mb;
		for(int i=0; i<=M; i+=d){
			ans+=seg.query(i,i+1);
		}
		cout<<ans<<endl;
	}
}