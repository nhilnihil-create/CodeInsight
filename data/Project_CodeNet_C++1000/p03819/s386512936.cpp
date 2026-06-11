#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

template <typename T0,typename T1,typename F0,typename F1,typename F2>
struct lazysegtree{
	//元データx[i]はv[n+i]
	//v[i]の親はv[i/2],子はv[i*2]とv[i*2+1]
	F0 func0;
	F1 func1;
	F2 func2;
	vector<T0> v0;
	vector<T1> v1;
	int n;
	int cnt;
	
	T0 init_value0;
	T1 init_value1;
	
	lazysegtree(int sz,F0 f0,F1 f1,F2 f2,T0 iv0,T1 iv1):func0(f0),func1(f1),func2(f2){
		init_value0 = iv0;
		init_value1 = iv1;
		n=1;
		cnt=0;
		while(true){
			if(n>=sz)break;
			n*=2;
			cnt++;
		}
		v0.resize(2*n,init_value0);
		v1.resize(2*n,init_value1);
		
	}
	
	lazysegtree(vector<T0> &x,F0 f0,F1 f1,F2 f2,T0 iv0,T1 iv1):func0(f0),func1(f1),func2(f2){
		init_value0 = iv0;
		init_value1 = iv1;
		n=1;
		cnt=0;
		while(true){
			if(n>=x.size())break;
			n*=2;
			cnt++;
		}
		v0.resize(2*n,init_value0);
		v1.resize(2*n,init_value1);
		for(int i=0;i<x.size();i++){
			v0[n+i]=x[i];
		}
		for(int i=n-1;i>=0;i--){
			v0[i]=func0(v0[i<<1],v0[(i<<1)+1]);
		}	
	}

	//2人の子供に伝える
	void propagate(int ind){
		update(ind<<1,v1[ind]);
		update((ind<<1)+1,v1[ind]);
		v1[ind] = init_value1;
	}
	
	//あるノードに対し先祖から伝播	
	void reflect(int l,int r){
		int j = cnt;
		while(l>>j==r>>j&&j>=1){
			propagate(l>>j);
			j--;
		}
		for(;j>=1;j--){
			propagate(l>>j);
			propagate(r>>j);
		}
	}
	
	//子供の値を親に伝える
	void mergeChildren(int ind){
		v0[ind] = func1(func0(v0[ind<<1],v0[(ind<<1)+1]),v1[ind],n>>(31-__builtin_clz(ind)));
	}
	
	//ある要素について作用させる
	void update(int ind,T1 x){
		v0[ind] = func1(v0[ind],x,n>>(31-__builtin_clz(ind)));
		v1[ind] = func2(v1[ind],x);
	}
	
	//[l,r)に対して作用させる
	void update(int l,int r,T1 x){
		if(l>=r)return;
		int L = l,R = r;
		l+=n;
		r+=n;
		reflect(l,r-1);
		while(true){
			if(l&1){
				update(l,x);
				l++;
			}
			if(r&1){
				update(r-1,x);
				r--;
			}
			if(l>=r)break;
			l>>=1;
			r>>=1;
		}
		
		l = L + n;
		r = R + n-1;
		
		while(true){
			l>>=1;
			r>>=1;
			if(l<=0)break;

			if(l==r){
				while(true){
					mergeChildren(l);
					l>>=1;
					if(!l)return;
				}
			}
			else{
				mergeChildren(l);
				mergeChildren(r);
			}
		}
		
	}
	
	//区間[l,r)におけるクエリ処理
	T0 query(int l,int r){
		T0 res1 = init_value0;
		T0 res2 = init_value0;
		if(l>=r)return res1;
		l+=n;
		r+=n;
		reflect(l,r-1);
		while(true){
			if(l&1){
				res1=func0(res1,v0[l]);
				l++;
			}
			if(r&1){
				res2=func0(v0[r-1],res2);
				r--;
			}
			if(l>=r)break;
			l>>=1;
			r>>=1;
		}
		return func0(res1,res2);
	}

	void show(){
		int n = 1;
		for(int i=1;i<v0.size();i++){
			for(int j=0;j<n;j++){
				if(j!=0)cout<<' ';
				cout<<v0[i+j];
			}
			cout<<endl;
			i+=n-1;
			n*=2;
		}
	}
	
};

int main(){
	
	int N,M;
	cin>>N>>M;
	
	vector<vector<int>> l(M,vector<int>());
	auto r = l;
	
	auto f0 = [](int a,int b){
		return a+b;
	};
	
	auto f1 = [](int a,int b,long long sz){
		return a+b*sz;
	};
	
	auto f2 = [](int a,int b){
		return a+b;
	};
	
	lazysegtree<int,int,decltype(f0),decltype(f1),decltype(f2)> seg(M+1,f0,f1,f2,0,0);
	
	for(int i=0;i<N;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		l[b-a].push_back(a);
		r[b-a].push_back(b);
	}
	
	
	int ans = N;
	for(int i=0;i<M;i++){
		for(int j=0;j<l[i].size();j++){
			ans--;
			seg.update(l[i][j],r[i][j]+1,1);
		}
		int temp = ans;
		for(int j=0;j<=M;j+=i+1){
			temp += seg.query(j,j+1);
		}

		printf("%d\n",temp);
	}
	
	
	return 0;
}