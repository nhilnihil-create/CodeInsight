#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


template <typename T>
struct segtree{
	//元データx[i]はv[n+i]
	//v[i]の親はv[i/2],子はv[i*2]とv[i*2+1]
	vector<T> v;
	int n;
	
	const T init_value = 0;
	
	segtree(vector<T> &x){
		n=1;
		while(true){
			if(n>=x.size())break;
			n*=2;
		}
		v.resize(2*n,init_value);
		
		for(int i=0;i<x.size();i++){
			v[n+i]=x[i];
		}
		for(int i=n-1;i>=0;i--){
			v[i]=func(v[i*2],v[i*2+1]);
		}
	}

	void update(int x,T val){
		x+=n;
		v[x]=val;
		while(true){
			x=(x)/2;
			v[x]=func(v[x*2],v[x*2+1]);
			if(x<=0)break;
		}
	}
	
	//区間[l,r)におけるクエリ処理
	T query(int l,int r){
		T res = init_value;
		l+=n;r+=n;
		while(true){
			if(l%2==1){
				res=func(v[l],res);
				l++;
			}
			if(r%2==1){
				res=func(v[r-1],res);
				r--;
			}
			if(l>=r)break;
			l/=2;r/=2;
		}
		return res;
	}
	T func(T a,T b){
		return a+b;
	}
	
	void show(){
		int n = 1;
		for(int i=1;i<v.size();i++){
			for(int j=0;j<n;j++){
				if(j!=0)cout<<' ';
				cout<<v[i+j];
			}
			cout<<endl;
			i+=n-1;
			n*=2;
		}
	}
	
};

int main(){
	
	long long N,K;
	cin>>N>>K;
	
	vector<long long> A(N);
	
	map<long long,int> mp;
	
	for(int i=0;i<N;i++){
		cin>>A[i];
		A[i] -= K;
		
		if(i!=0)A[i] += A[i-1];
		
		mp[A[i]] = -1;	
		mp[-A[i]] = -1;
	}
	

	int cnt = 0;
	for(auto &a:mp){
		a.second = cnt;
		cnt++;
	}
	
	vector<long long> v(cnt,0);
	segtree<long long> S(v);
	long long ans = 0;
	for(int i=0;i<N;i++){
		if(A[i]>=0)ans++;
		ans += S.query(0,mp[A[i]]+1);
		S.update(mp[A[i]],S.query(mp[A[i]],mp[A[i]]+1)+1);
	}
	
	cout<<ans<<endl;
	
	return 0;
}
